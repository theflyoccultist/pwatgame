#include "EnemyManager.hpp"

void EnemyManager::init() { factory.loadAssets(); }

void EnemyManager::spawnEnemies(EnemyType type, int count) {
  enemyCount += count;
  for (int i = 0; i < count; ++i) {
    Vector2 pos = {Random::rangeFloat(0, 730.0f),
                   Random::rangeFloat(0, 730.0f)};

    auto e = factory.create(type, pos);
    if (e)
      enemies.push_back(std::move(e));
  }
}

void EnemyManager::updateAll(float delta, const PlayerState &state,
                             const std::vector<Vector2> &bulletPositions) {
  if (state.damageCooldown > 0.0f)
    state.damageCooldown -= delta;

  for (std::unique_ptr<Enemy> &e : enemies) {
    e->update(delta, state.position);
    e->takeBulletIfHit(bulletPositions, 10.0f, e);

    if (e->type == EnemyType::SWARMER) {
      e->contactDMG(state.position, state.playerSize, e->position, e->size);
    }

    if (e->type == EnemyType::SNIPER) {
      e->shoot(e->position, {0, -1}, delta);
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
