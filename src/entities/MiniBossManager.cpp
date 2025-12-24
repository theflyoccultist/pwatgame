#include "MiniBossManager.hpp"
#include "../collisions/CollisionDetection.hpp"
#include "Actor.hpp"

void MiniBossManager::spawnMiniBoss(MiniBossType type) {
  for (auto *&slot : miniBosses) {
    if (!slot || !slot->isActive()) {
      Vector2 pos = {320, 320};
      auto &spec = MiniBossDatabase::get(type);
      MiniBoss *m = factory.create(type, pos, spec);

      if (m) {
        slot = m;
        m->activate();
        break;
      }
    }
  }
};

bool MiniBossManager::updateAll(float dt, const PlayerState &player,
                                std::span<Projectile *const> bullets) {
  using namespace Collisions;
  miniBossTimer += dt;
  float bossCooldown = std::fmodf(miniBossTimer, 16.0f);

  for (auto *m : miniBosses) {
    if (!m || !m->isAlive())
      continue;

    Vector2 bulletStartPos = {m->stats.pos.x + (float)m->stats.size / 2,
                              m->stats.pos.y + (float)m->stats.size / 2};

    p.startPos = bulletStartPos;
    p.playerPos = player.position;
    p.dt = dt;

    m->update(p, projMan, bossCooldown);

    for (auto &b : bullets) {
      if (!b || !b->isActive())
        continue;

      if (b->faction == Faction::Player &&
          checkBulletInteraction(b->stats.pos, (float)b->stats.size,
                                 m->stats.pos, (float)m->stats.size)) {
        player.addScore(1);
        b->expire();

        if (m->takeBulletIfHit(b->stats.damage))
          AudioSystem::instance().sfx->enemyKilled();
      }

      if (b->faction == Faction::Enemy &&
          checkBulletInteraction(b->stats.pos, (float)b->stats.size,
                                 player.position, (float)player.playerSize)) {
        if (player.tryApplyPlayerDmg(b->stats.damage))
          b->expire();
      }
    }
  }

  bool isMiniBossKilled = false;

  for (auto &m : miniBosses) {
    if (m && !m->isAlive()) {
      m->deactivate();
      m = nullptr;
      isMiniBossKilled = true;
      player.addScore(500);
    }
  }

  return isMiniBossKilled;
};
