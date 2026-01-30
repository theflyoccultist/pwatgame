#pragma once

#include "../player/PlayerState.hpp"
#include "Enemy.hpp"
#include "EnemyFactory.hpp"
#include <array>
#include <raylib.h>
#include <span>

class EnemyManager {
public:
  EnemyManager(ProjectileManager &pm) : projMan(pm) {}
  void init();
  void spawnEnemy(const Vector2 &pos, EnemyType type);
  void updateAll(float delta, const PlayerState &player,
                 std::span<Projectile *const> bullets);

  void drawAll();
  void clearAll();
  void resetTimer() { enemyTimer = 0.0f; }

private:
  static constexpr int ENEMY_POOL = 350;
  std::array<Enemy *, ENEMY_POOL> enemies{};
  EnemyFactory factory;

  ProjectileManager &projMan;
  Actor::ShootParams p;
  float enemyTimer = 0.0f;
};
