#include "../CollisionDetection.hpp"
#include "../Game.hpp"
#include "../sound/AudioSystem.hpp"
#include "../texture/AssetSystem.hpp"
#include "../utils/Random.hpp"
#include <array>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <raylib.h>
#include <string>

vector<Entity> enemies;
std::array<Texture2D *, 3> enemyAssets;

void EntityManager::spawnEnemies(EnemyType type, size_t count) {
  enemies.clear();
  enemiesCount = count;

  for (size_t i = 0; i < enemiesCount; ++i) {
    Vector2 pos = {Random::rangeFloat(0.0f, 730.0f),
                   Random::rangeFloat(0.0f, 730.0f)};

    int currentHP = Random::rangeInt(120, 300);
    float speed = Random::rangeFloat(30.0f, 70.0f);
    float enemySize = 60.0f;

    Entity enemy = {EntityType::ENEMY, pos,       {0, 0}, true,
                    currentHP,         currentHP, speed,  enemySize};

    enemies.push_back(enemy);

    const std::array<std::string, 3> enemyPaths = {
        "../assets/enemies/enemy_HIGH.png", "../assets/enemies/enemy_MED.png",
        "../assets/enemies/enemy_LOW.png"};

    if (type == EnemyType::SWARMER) {
      for (size_t i = 0; i < enemyPaths.size(); ++i) {
        enemyAssets[i] = &AssetSystem::instance().loadTexture(
            enemyPaths[i], enemySize, enemySize);
      }
    }
  }
}

const vector<Entity> &getEnemies() { return enemies; }

void EntityManager::updateEnemies(const vector<Vector2> &bulletPositions,
                                  Vector2 playerPos) {

  if (PlayerState::damageCooldown > 0.0f)
    PlayerState::damageCooldown -= Game::deltaTime;

  for (auto &enemy : enemies) {
    Vector2 dir = {playerPos.x - enemy.position.x,
                   playerPos.y - enemy.position.y};

    float length = std::sqrt(dir.x * dir.x + dir.y * dir.y);
    if (length > 0.0f) {
      dir.x /= length;
      dir.y /= length;
    }

    enemy.position.x += dir.x * enemy.entitySpeed * Game::deltaTime;
    enemy.position.y += dir.y * enemy.entitySpeed * Game::deltaTime;

    if (enemy.active && Collisions::checkPlayerInteraction(playerPos, enemy)) {
      if (PlayerState::damageCooldown <= 0.0f) {
        PlayerState::health--;
        PlayerState::damageCooldown = 0.10f;
      }
      if (PlayerState::health <= 0)
        std::cout << "Game Over!\n";
    }

    for (auto &bulletPos : bulletPositions) {
      if (enemy.active &&
          Collisions::checkBulletInteraction(bulletPos, enemy)) {
        enemy.currentEntityHP--;
        PlayerState::score++;
        if (enemy.currentEntityHP <= 0) {
          AudioSystem::instance().enemyKilled();
          enemy.active = false;
          enemiesCount--;
          break;
        }
      }
    }
  }

  std::erase_if(enemies, [](const Entity &e) { return !e.active; });
}

void EntityManager::drawEnemies(EnemyType type) {
  if (type == EnemyType::SWARMER) {
    for (auto &enemy : enemies) {

      if (enemy.currentEntityHP > 200)
        AssetSystem::instance().drawTexture(enemyAssets[0], enemy.position.x,
                                            enemy.position.y);
      else if (enemy.currentEntityHP > 100)
        AssetSystem::instance().drawTexture(enemyAssets[1], enemy.position.x,
                                            enemy.position.y);
      else
        AssetSystem::instance().drawTexture(enemyAssets[2], enemy.position.x,
                                            enemy.position.y);

      DrawText(
          TextFormat("%d / %d", enemy.currentEntityHP, enemy.totalEntityHP),
          enemy.position.x + 20, enemy.position.y - 20, 10, BLACK);
    }
  }
}
