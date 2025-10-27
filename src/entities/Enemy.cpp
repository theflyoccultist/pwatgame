#include "Enemy.hpp"
#include "../collisions/CollisionDetection.hpp"
#include "../sound/AudioSystem.hpp"
#include <iostream>
#include <memory>
#include <raylib.h>
#include <vector>

void Enemy::takeBulletIfHit(const std::vector<Vector2> &bulletPositions,
                            const float &bulletSize,
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

void Enemy::contactDMG(const PlayerState &state,
                       const std::unique_ptr<Enemy> &enemy) {
  if (Collisions::checkPlayerInteraction(state.position, state.playerSize,
                                         enemy->position, enemy->size)) {
    if (PlayerState::damageCooldown <= 0.0f) {
      PlayerState::health--;
      PlayerState::damageCooldown = 0.10f;
    }
    if (PlayerState::health <= 0)
      std::cout << "Game Over!\n";
  }
}
