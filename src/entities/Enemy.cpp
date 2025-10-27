#include "Enemy.hpp"
#include "../Player.hpp"
#include "../collisions/CollisionDetection.hpp"
#include "../projectiles/ProjectileManager.hpp"
#include "../sound/AudioSystem.hpp"
#include <iostream>
#include <memory>
#include <raylib.h>
#include <vector>

void Enemy::takeBulletIfHit(const std::vector<Vector2> &bulletPositions,
                            float bulletSize,
                            const std::unique_ptr<Enemy> &enemy) {
  for (auto &bulletPos : bulletPositions) {
    if (Collisions::checkBulletInteraction(bulletPos, bulletSize,
                                           enemy->position, enemy->size)) {
      enemy->currentHP--;
      PlayerState::score++;
      if (enemy->currentHP <= 0) {
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

void Enemy::shootPlayer(const Vector2 &bulletPos, float bulletSize,
                        const Vector2 &playerPos, float playerSize,
                        const Vector2 &startPosition, const Vector2 &dir,
                        float dt) {
  shoot(startPosition, dir, dt);

  if (Collisions::checkBulletInteraction(bulletPos, bulletSize, playerPos,
                                         playerSize)) {

    if (PlayerState::damageCooldown <= 0.0f) {
      PlayerState::health--;
      PlayerState::damageCooldown = 0.10f;
    }
    if (PlayerState::health <= 0)
      std::cout << "Game Over!\n";
  }
}

void Enemy::shoot(Vector2 startPosition, Vector2 dir, float dt) {
  shootTimer -= dt;
  if (shootTimer <= 0.0f) {
    ProjectileManager::instance().spawn(ProjectileType::LONGRANGE,
                                        startPosition, dir);
    shootTimer = shootCooldown;
  }

  shootTimer = 0.0f;
}
