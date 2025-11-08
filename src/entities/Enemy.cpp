#include "Enemy.hpp"
#include "Faction.hpp"
#include <cmath>
#include <raylib.h>

bool Enemy::takeBulletIfHit(int dmg) {
  currentHP -= dmg;
  return currentHP <= 0;
}

void Enemy::shootTowardsPlayer(ProjectileManager &projMan,
                               const Vector2 &startPos,
                               const Vector2 &playerPos, float dt,
                               float shootCooldown) {
  Vector2 direction = {playerPos.x - startPos.x, playerPos.y - startPos.y};
  float len = std::sqrt(direction.x * direction.x + direction.y * direction.y);
  if (len != 0) {
    direction.x /= len;
    direction.y /= len;
  }

  shootTimer -= dt;
  if (shootTimer <= 0.0f) {
    projMan.spawn(Faction::Enemy, ProjectileType::LONGRANGE, startPos,
                  direction);
    shootTimer = shootCooldown;
  }
}
