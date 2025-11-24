#include "MiniBossManager.hpp"
#include "../collisions/CollisionDetection.hpp"
#include "Actor.hpp"
#include "MiniBossDatabase.hpp"
#include <utility>

void MiniBossManager::spawnMiniBoss(MiniBossType type) {
  Vector2 pos = {320, 320};
  auto e = factory.create(type, pos);

  if (e)
    miniBosses.push_back(std::move(e));
};

bool MiniBossManager::updateAll(float dt, const PlayerState &player,
                                std::span<Projectile *const> bullets) {
  using namespace Collisions;

  for (auto &m : miniBosses) {
    m->update(dt, player.position);

    for (auto &b : bullets) {
      if (b->faction == Faction::Player &&
          checkBulletInteraction(b->stats.pos, (float)b->stats.size,
                                 m->position, (float)m->size)) {
        player.score++;
        b->expire();
        if (m->takeBulletIfHit(b->stats.damage))
          AudioSystem::instance().sfx->enemyKilled();
      }
    }

    Vector2 bulletStartPos = {m->position.x + (float)m->size / 2,
                              m->position.y + (float)m->size / 2};

    Actor::ShootParams p;
    p.startPos = bulletStartPos;
    p.playerPos = player.position;
    p.dt = dt;

    p.type = MiniBossDatabase::getWeaponType(m->type);
    p.spec = MiniBossDatabase::getWeaponSpec(m->type);

    if (m->type == MiniBossType::WINDOWS) {
      m->shootTowardsPlayer(projMan, p);
    }
  }

  bool isMiniBossKilled = static_cast<bool>(
      std::erase_if(miniBosses, [](auto &p) { return !p->isAlive(); }));

  return isMiniBossKilled;
};
