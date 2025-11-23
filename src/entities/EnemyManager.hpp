#pragma once

#include "../player/Player.hpp"
#include "Enemy.hpp"
#include "EnemyFactory.hpp"
#include <array>
#include <raylib.h>
#include <span>

class EnemyManager {
public:
  EnemyManager(ProjectileManager &pm) : projMan(pm) {}
  void init();
  void spawnEnemies(EnemyType type, int count = 1);
  void updateAll(float delta, const PlayerState &player,
                 std::span<Projectile *const> bullets);

  void drawAll();
  void clearAll();

private:
  static constexpr int ENEMY_POOL = 350;
  std::array<Enemy *, ENEMY_POOL> enemies{};
  EnemyFactory factory;
  void applyPlayerDmg(const PlayerState &player, int damage);

  ProjectileManager &projMan;
};
