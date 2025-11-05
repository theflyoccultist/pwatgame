#include "EnemyManager.hpp"
#include "../collisions/CollisionDetection.hpp"
#include "../sound/AudioSystem.hpp"

void EnemyManager::init() { factory.loadAssets(); }

void EnemyManager::spawnEnemies(EnemyType type, int count) {
  enemies.reserve(enemies.size() + count);
  for (int i = 0; i < count; ++i) {
    Vector2 pos = {Random::rangeFloat(0, 730.0f),
                   Random::rangeFloat(0, 730.0f)};

    auto e = factory.create(type, pos);
    if (e)
      enemies.push_back(std::move(e));
  }
}

void EnemyManager::updateAll(float delta, const PlayerState &player,
                             std::span<Projectile *const> bullets) {
  if (player.damageCooldown > 0.0f)
    player.damageCooldown -= delta;

  for (auto &e : enemies) {
    e->update(delta, player.position);

    for (auto &b : bullets) {
      if (Collisions::checkBulletInteraction(b->position, b->size, e->position,
                                             e->size)) {
        b->expire();
        if (e->takeBulletIfHit(b->damage)) {
          player.score++;
          AudioSystem::instance().enemyKilled();
        }
      }
    }

    if (e->type == EnemyType::SWARMER) {
      if (Collisions::checkPlayerInteraction(player.position, player.playerSize,
                                             e->position, e->size)) {

        if (player.damageCooldown <= 0.0f) {
          player.health--;
          player.damageCooldown = 0.10f;
        }
      }
    }

    if (e->type == EnemyType::SNIPER) {
      e->shootTowardsPlayer(
          {e->position.x + e->size / 2, e->position.y + e->size / 2},
          player.position, delta);
    }
  }

  std::erase_if(enemies,
                [](const std::unique_ptr<Enemy> &p) { return !p->isAlive(); });

  enemyCount = enemies.size();
}

void EnemyManager::drawAll() {
  for (auto &e : enemies)
    e->draw();
}

void EnemyManager::clearAll() {
  enemies.clear();
  enemyCount = 0;
}
