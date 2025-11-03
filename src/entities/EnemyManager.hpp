#pragma once

#include "../Player.hpp"
#include "Enemy.hpp"
#include "EnemyFactory.hpp"
#include <memory>
#include <raylib.h>
#include <vector>

class EnemyManager {
public:
  static inline int enemyCount;
  void init();
  void spawnEnemies(EnemyType type, int count);
  void updateAll(float delta, const PlayerState &player,
                 const std::vector<Vector2> &bulletPositions);
  void drawAll();
  void clearAll();

private:
  std::vector<std::unique_ptr<Enemy>> enemies;
  EnemyFactory factory;
};
