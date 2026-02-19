#include <collisions/CollisionDetection.hpp>
#include <entities/WallManager.hpp>

#include <cmath>
#include <span>

void WallManager::init() { factory.loadAssets(); }

void WallManager::spawnWall(WallType type, const Vector2 &pos,
                            const WallSpec &spec) {
  Wall *w = factory.create(type, pos, spec);
  if (!w)
    return;

  for (auto &slot : walls) {
    if (slot == nullptr) {
      slot = w;
      return;
    }
  }
}

void WallManager::updateAll(float delta, const PlayerState &player,
                            std::span<Projectile *const> bullets) {
  using namespace Collisions;
  wallTimer += delta;
  float wallCooldown = std::fmodf(wallTimer, 8.0f);

  for (auto *w : walls) {
    if (!w || !w->isActive())
      continue;

    bool touchPlayer = checkPlayerInteraction(
        player.position, (float)player.playerSize, w->stats.pos, w->stats.size);

    if (touchPlayer) {
      player.tryApplyPlayerDmg(w->stats.contactDmg);
    }

    w->update({delta, wallCooldown});

    for (auto &b : bullets) {
      if (!b || !b->isActive())
        continue;

      if (checkBulletInteraction(b->stats.pos, b->stats.size, w->stats.pos,
                                 w->stats.size) &&
          w->stats.collision)
        b->expire();
    }
  }

  for (auto &w : walls) {
    if (w && !w->isActive()) {
      w->deactivateWall();
      w = nullptr;
    }
  }
}

void WallManager::drawAll() {
  for (auto *w : walls) {
    if (w && w->isActive())
      w->draw();
  }
}

void WallManager::clearAll() {
  for (auto *&p : walls) {
    if (p) {
      p->deactivateWall();
      p = nullptr;
    }
  }
}
