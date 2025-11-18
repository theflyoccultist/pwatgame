#include "MiniBossManager.hpp"
#include "../collisions/CollisionDetection.hpp"
#include <utility>

void MiniBossManager::spawnMiniBoss(BossType type) {
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
          checkBulletInteraction(b->position, (float)b->size, m->position,
                                 (float)m->size)) {
        player.score++;
        b->expire();
        m->takeBulletIfHit(b->damage);
      }
    }

    Vector2 bulletStartPos = {m->position.x + (float)m->size / 2,
                              m->position.y + (float)m->size / 2};

    if (m->type == BossType::WINDOWS) {
      m->shootTowardsPlayer(projMan, {bulletStartPos, player.position, dt, 0.3f,
                                      ProjectileType::STRAIGHT});
    }
  }

  bool isMiniBossKilled = static_cast<bool>(
      std::erase_if(miniBosses, [](auto &p) { return !p->isAlive(); }));

  return isMiniBossKilled;
};
