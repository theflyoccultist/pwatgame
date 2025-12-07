#include "MiniBossManager.hpp"
#include "../collisions/CollisionDetection.hpp"
#include "Actor.hpp"
#include "MiniBossDatabase.hpp"

void MiniBossManager::spawnMiniBoss(MiniBossType type) {
  for (auto *&slot : miniBosses) {
    if (!slot || !slot->isActive()) {
      Vector2 pos = {320, 320};
      auto &spec = MiniBossDatabase::get(type);
      MiniBoss *m = factory.create(type, pos, spec);

      if (m) {
        slot = m;
        m->activate();
      }
    }
  }
};

void MiniBossManager::applyPlayerDmg(const PlayerState &player, int damage) {
  if (player.damageCooldown <= 0.0f) {
    player.health -= damage;
    player.damageCooldown = 0.10f;
  }
}

bool MiniBossManager::updateAll(float dt, const PlayerState &player,
                                std::span<Projectile *const> bullets) {
  using namespace Collisions;
  miniBossTimer += dt;
  float bossCooldown = std::fmodf(miniBossTimer, 8.0f);

  for (auto *m : miniBosses) {
    if (!m || !m->isAlive())
      continue;

    m->update(dt, player.position, bossCooldown);

    for (auto &b : bullets) {
      if (!b || !b->isActive())
        continue;

      if (b->faction == Faction::Player &&
          checkBulletInteraction(b->stats.pos, (float)b->stats.size,
                                 m->stats.pos, (float)m->stats.size)) {
        player.score++;
        b->expire();

        if (m->takeBulletIfHit(b->stats.damage))
          AudioSystem::instance().sfx->enemyKilled();
      }

      if (b->faction == Faction::Enemy &&
          checkBulletInteraction(b->stats.pos, (float)b->stats.size,
                                 player.position, (float)player.playerSize)) {
        applyPlayerDmg(player, b->stats.damage);
        b->expire();
      }
    }

    Vector2 bulletStartPos = {m->stats.pos.x + (float)m->stats.size / 2,
                              m->stats.pos.y + (float)m->stats.size / 2};

    Actor::ShootParams p;
    p.startPos = bulletStartPos;
    p.playerPos = player.position;
    p.dt = dt;

    p.type = MiniBossDatabase::getWeaponType(m->type);
    p.spec = MiniBossDatabase::getWeaponSpec(m->type);

    if (bossCooldown >= 4.0f)
      m->shootTowardsPlayer(projMan, p);
  }

  bool isMiniBossKilled = false;

  for (auto &m : miniBosses) {
    if (m && !m->isAlive()) {
      m->deactivate();
      m = nullptr;
      isMiniBossKilled = true;
    }
  }

  return isMiniBossKilled;
};
