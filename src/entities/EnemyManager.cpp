#include "EnemyManager.hpp"

void EnemyManager::init() { factory.loadAssets(); }

void EnemyManager::spawnEnemies(EnemyType type, int count) {
  enemyCount += count;
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
                             const std::vector<Vector2> &bulletPositions) {
  if (player.damageCooldown > 0.0f)
    player.damageCooldown -= delta;

  for (std::unique_ptr<Enemy> &e : enemies) {
    e->update(delta, player.position);
    e->takeBulletIfHit(bulletPositions, 10.0f);

    if (e->type == EnemyType::SWARMER) {
      e->contactDMG(player.position, player.playerSize, e->position, e->size);
    }

    if (e->type == EnemyType::SNIPER) {
      e->shootTowardsPlayer(
          {e->position.x + e->size / 2, e->position.y + e->size / 2},
          player.position, delta);
    }

    if (!e->isAlive())
      enemyCount--;
  }

  std::erase_if(enemies,
                [](const std::unique_ptr<Enemy> &p) { return !p->isAlive(); });
}

void EnemyManager::drawAll() {
  for (auto &e : enemies)
    e->draw();
}

void EnemyManager::clearAll() {
  enemies.clear();
  enemyCount = 0;
}
