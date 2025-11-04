#include "Enemy.hpp"
#include "../Player.hpp"
#include "../projectiles/ProjectileManager.hpp"
#include <cmath>
#include <iostream>
#include <raylib.h>

bool Enemy::takeBulletIfHit() {
  currentHP--;
  PlayerState::score++;
  return currentHP <= 0;
}

void Enemy::contactDMG() {
  if (PlayerState::damageCooldown <= 0.0f) {
    PlayerState::health--;
    PlayerState::damageCooldown = 0.10f;
  }
  if (PlayerState::health <= 0)
    std::cout << "Game Over!\n";
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
    ProjectileManager::instance().spawn(ProjectileType::LONGRANGE,
                                        startPosition, dir);
    shootTimer = shootCooldown;
  }
}
