#pragma once

#include "../projectiles/Projectile.hpp"
#include "Enemy.hpp"
#include "EnemyFactory.hpp"
#include "Player.hpp"
#include <memory>
#include <raylib.h>
#include <span>
#include <vector>

class EnemyManager {
public:
  static inline int enemyCount;
  void init();
  void spawnEnemies(EnemyType type, int count);
  void updateAll(float delta, const PlayerState &player,
                 std::span<Projectile *const> bullets);

  void drawAll();
  void clearAll();

private:
  std::vector<std::unique_ptr<Enemy>> enemies;
  EnemyFactory factory;
};
