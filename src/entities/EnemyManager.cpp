#include <collisions/CollisionDetection.hpp>
#include <entities/EnemyManager.hpp>
#include <sound/AudioSystem.hpp>

void EnemyManager::init() { factory.loadAssets(); }

void EnemyManager::spawnEnemy(const Vector2 &pos, EnemyType type) {
  for (auto *&slot : enemies) {
    if (!slot || !slot->isActive()) {
      auto &spec = EnemyDatabase::get(type);
      Enemy *e = factory.create(type, pos, spec);

      if (e) {
        slot = e;
        e->activate();
        break;
      }
    }
  }
}

void EnemyManager::updateAll(float delta, const PlayerState &player,
                             std::span<Projectile *const> bullets) {
  using namespace Collisions;
  enemyTimer += delta;
  float enemyCooldown = std::fmodf(enemyTimer, 8.0f);

  for (auto *e : enemies) {
    if (!e || !e->isAlive())
      continue;

    bool touchPlayer =
        checkPlayerInteraction(player.position, (float)player.playerSize,
                               e->stats.pos, (float)e->stats.size);
    if (touchPlayer) {
      player.tryApplyPlayerDmg(e->stats.contactDmg);
    }

    Vector2 bulletStartPos = {e->stats.pos.x + (float)e->stats.size / 2,
                              e->stats.pos.y + (float)e->stats.size / 2};

    shootParams.startPos = bulletStartPos;
    shootParams.playerPos = player.position;
    shootParams.dt = delta;

    e->update(shootParams, projMan, enemyCooldown);

    for (auto &b : bullets) {
      if (!b || !b->isActive())
        continue;

      if (b->faction == Faction::Player &&
          checkBulletInteraction(b->stats.pos, (float)b->stats.size,
                                 e->stats.pos, (float)e->stats.size)) {
        player.addScore(1);
        b->expire();

        if (e->takeBulletIfHit(b->stats.damage)) {
          AudioSystem::instance().sfx->enemyKilled();
        }
      }

      if (b->faction == Faction::Enemy &&
          checkBulletInteraction(b->stats.pos, (float)b->stats.size,
                                 player.position, (float)player.playerSize)) {
        if (player.tryApplyPlayerDmg(b->stats.damage))
          b->expire();
      }
    }
  }

  for (auto &e : enemies) {
    if (e && !e->isAlive()) {
      e->deactivate();
      e = nullptr;
    }
  }
}

void EnemyManager::drawAll() {
  for (auto *e : enemies) {
    if (e && e->isAlive())
      e->draw();
  }
}

void EnemyManager::clearAll() {
  for (auto *&p : enemies) {
    if (p) {
      p->deactivate();
      p = nullptr;
    }
  }
}
