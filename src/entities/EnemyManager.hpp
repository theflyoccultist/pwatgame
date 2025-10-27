#pragma once

#include "Enemy.hpp"
#include "EnemyFactory.hpp"
#include <memory>
#include <raylib.h>
#include <utility>
#include <vector>

class EnemyManager {
public:
  static inline int enemyCount;

  void init() { factory.loadAssets(); }

  void spawnEnemies(EnemyType type, int count) {
    enemyCount += count;
    for (int i = 0; i < count; ++i) {
      Vector2 pos = {Random::rangeFloat(0, 730.0f),
                     Random::rangeFloat(0, 730.0f)};

      auto e = factory.create(type, pos);
      if (e)
        enemies.push_back(std::move(e));
    }
  }

  void updateAll(float delta, const PlayerState &state,
                 const std::vector<Vector2> &bulletPositions) {
    if (PlayerState::damageCooldown > 0.0f)
      PlayerState::damageCooldown -= delta;

    for (std::unique_ptr<Enemy> &e : enemies) {
      e->update(delta, state.position);
      Enemy::takeBulletIfHit(bulletPositions, 10.0f, e);

      if (e->type == EnemyType::SWARMER)
        Enemy::contactDMG(state, e);

      if (!e->isAlive())
        enemyCount--;
    }

    std::erase_if(
        enemies, [](const std::unique_ptr<Enemy> &p) { return !p->isAlive(); });
  }

  void drawAll() {
    for (auto &e : enemies)
      e->draw();
  }

  void clearAll() { enemies.clear(); }

private:
  std::vector<std::unique_ptr<Enemy>> enemies;
  EnemyFactory factory;
};
