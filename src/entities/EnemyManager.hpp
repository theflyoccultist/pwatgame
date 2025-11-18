#pragma once

#include "../player/Player.hpp"
#include "Enemy.hpp"
#include "EnemyFactory.hpp"
#include <memory>
#include <raylib.h>
#include <span>
#include <vector>

class EnemyManager {
public:
  EnemyManager(ProjectileManager &pm) : projMan(pm) {}
  static inline u_int enemyCount;
  void init();
  void spawnEnemies(EnemyType type, int count = 1);
  void updateAll(float delta, const PlayerState &player,
                 std::span<Projectile *const> bullets);

  void drawAll();
  void clearAll();

private:
  std::vector<std::unique_ptr<Enemy>> enemies;
  EnemyFactory factory;
  void applyPlayerDmg(const PlayerState &player, int damage);

  ProjectileManager &projMan;
};
