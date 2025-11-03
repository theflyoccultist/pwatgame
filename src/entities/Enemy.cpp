#include "Enemy.hpp"
#include "../Player.hpp"
#include "../collisions/CollisionDetection.hpp"
#include "../projectiles/ProjectileManager.hpp"
#include "../sound/AudioSystem.hpp"
#include <cmath>
#include <iostream>
#include <raylib.h>
#include <vector>

void Enemy::takeBulletIfHit(const std::vector<Vector2> &bulletPositions,
                            float bulletSize) {
  for (auto &bulletPos : bulletPositions) {
    if (Collisions::checkBulletInteraction(bulletPos, bulletSize, position,
                                           size)) {
      currentHP--;
      PlayerState::score++;
      if (currentHP <= 0) {
        AudioSystem::instance().enemyKilled();
        break;
      }
    }
  }
}

void Enemy::contactDMG(const Vector2 &playerPos, float playerSize,
                       const Vector2 &enemyPos, float enemySize) {
  if (Collisions::checkPlayerInteraction(playerPos, playerSize, enemyPos,
                                         enemySize)) {
    if (PlayerState::damageCooldown <= 0.0f) {
      PlayerState::health--;
      PlayerState::damageCooldown = 0.10f;
    }
    if (PlayerState::health <= 0)
      std::cout << "Game Over!\n";
  }
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
