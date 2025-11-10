#include "Enemy.hpp"
#include "Faction.hpp"
#include <cmath>
#include <raylib.h>

bool Enemy::takeBulletIfHit(int dmg) {
  currentHP -= dmg;
  return currentHP <= 0;
}

void Enemy::shoot(ProjectileManager &pm, const ShootParams &p,
                  const Vector2 &direction) {
  shootTimer -= p.dt;
  if (shootTimer <= 0.0f) {
    pm.spawn(Faction::Enemy, p.type, p.startPos, direction);
    shootTimer = p.cooldown;
  }
}

void Enemy::shootTowardsPlayer(ProjectileManager &pm, const ShootParams &p) {
  Vector2 direction = {p.playerPos.x - p.startPos.x,
                       p.playerPos.y - p.startPos.y};
  float len = std::sqrt(direction.x * direction.x + direction.y * direction.y);
  if (len != 0) {
    direction.x /= len;
    direction.y /= len;
  }

  shoot(pm, p, direction);
}

void Enemy::shootInVoid(ProjectileManager &pm, const ShootParams &p) {
  Vector2 direction;
  isX ? direction = {-1, 0} : direction = {0, -1};

  shoot(pm, p, direction);
}
