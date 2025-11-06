#include "Enemy.hpp"
#include "../entities/Faction.hpp"
#include "../projectiles/ProjectileManager.hpp"
#include <cmath>
#include <raylib.h>

bool Enemy::takeBulletIfHit(int dmg) {
  currentHP -= dmg;
  return currentHP <= 0;
}

void Enemy::shootTowardsPlayer(const Vector2 &startPos,
                               const Vector2 &playerPos, float dt) {
  Vector2 direction = {playerPos.x - startPos.x, playerPos.y - startPos.y};
  float len = std::sqrt(direction.x * direction.x + direction.y * direction.y);
  if (len != 0) {
    direction.x /= len;
    direction.y /= len;
  }
  shoot(startPos, direction, dt);
}

void Enemy::shoot(const Vector2 &startPosition, const Vector2 &dir, float dt) {
  shootTimer -= dt;
  if (shootTimer <= 0.0f) {
    ProjectileManager::instance().spawn(
        Faction::Enemy, ProjectileType::LONGRANGE, startPosition, dir);
    shootTimer = shootCooldown;
  }
}
