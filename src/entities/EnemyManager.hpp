#pragma once

#include "../Player.hpp"
#include "Enemy.hpp"
#include "EnemyFactory.hpp"
#include <memory>
#include <raylib.h>
#include <utility>
#include <vector>

class EnemyManager {
public:
  void init() { factory.loadAssets(); }

  void spawnEnemies(EnemyType type, int count) {
    for (int i = 0; i < count; ++i) {
      Vector2 pos = {Random::rangeFloat(0, 730.0f),
                     Random::rangeFloat(0, 730.0f)};

      auto e = factory.create(type, pos);
      if (e)
        enemies.push_back(std::move(e));
    }
  }

  void updateAll(float delta, Vector2 playerPos,
                 const std::vector<Vector2> &bulletPositions) {
    if (PlayerState::damageCooldown > 0.0f)
      PlayerState::damageCooldown -= delta;

    for (std::unique_ptr<Enemy> &e : enemies) {
      e->update(delta, playerPos);
      Enemy::takeBulletIfHit(e, bulletPositions);
      Enemy::giveDMGIfTouched(playerPos, e->position);
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
