#include "../collisions/CollisionDetection.hpp"
#include "../sound/AudioSystem.hpp"
#include "../texture/AssetSystem.hpp"
#include <array>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <raylib.h>
#include <string>
#include <unordered_map>

vector<Enemy> enemies;
const int numAssets = static_cast<int>(EnemyType::COUNT) * 3;
std::array<Texture2D *, numAssets> enemyAssets;

static const std::unordered_map<EnemyType, std::array<std::string, 3>>
    enemyTexturePaths = {{EnemyType::SWARMER,
                          {"../assets/enemies/swarmer_HIGH.png",
                           "../assets/enemies/swarmer_MED.png",
                           "../assets/enemies/swarmer_LOW.png"}},
                         {EnemyType::SNIPER,
                          {"../assets/enemies/sniper_HIGH.png",
                           "../assets/enemies/sniper_MED.png",
                           "../assets/enemies/sniper_LOW.png"}}};

void EnemyManager::clearEnemies() {
  enemies.clear();
  enemiesCount = 0;
}

void EnemyManager::spawnEnemies(EnemyType type, size_t count) {
  enemiesCount += count;

  for (size_t i = 0; i < count; ++i) {
    Vector2 pos = {Random::rangeFloat(0.0f, 730.0f),
                   Random::rangeFloat(0.0f, 730.0f)};

    int currentHP = Random::rangeInt(120, 300);
    float speed = Random::rangeFloat(30.0f, 70.0f);
    float enemySize = 60.0f;

    Enemy enemy = {type,      pos,       {0, 0}, true,
                   currentHP, currentHP, speed,  enemySize};

    enemies.push_back(enemy);

    auto it = enemyTexturePaths.find(type);
    if (it != enemyTexturePaths.end()) {
      const auto &paths = it->second;
      for (size_t i = 0; i < paths.size(); ++i) {
        enemyAssets[i] = &AssetSystem::instance().loadTexture(
            paths[i], enemySize, enemySize);
      }
    }
  }
}

void EnemyManager::updateEnemies(float deltaTime,
                                 const vector<Vector2> &bulletPositions,
                                 Vector2 playerPos) {

  if (PlayerState::damageCooldown > 0.0f)
    PlayerState::damageCooldown -= deltaTime;

  for (auto &enemy : enemies) {
    Vector2 dir = {playerPos.x - enemy.position.x,
                   playerPos.y - enemy.position.y};

    float length = std::sqrt(dir.x * dir.x + dir.y * dir.y);
    if (length > 0.0f) {
      dir.x /= length;
      dir.y /= length;
    }

    enemy.position.x += dir.x * enemy.entitySpeed * deltaTime;
    enemy.position.y += dir.y * enemy.entitySpeed * deltaTime;

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

  std::erase_if(enemies, [](const Enemy &e) { return !e.active; });
}

void EnemyManager::drawAll() {
  for (auto &enemy : enemies) {
    enemy.draw();
  }
}

void Enemy::draw() const {
  Texture2D *texture = nullptr;

  switch (type) {
  case EnemyType::SWARMER:
    if (currentEntityHP > totalEntityHP * 0.66f)
      texture = enemyAssets[0];
    else if (currentEntityHP > totalEntityHP * 0.33f)
      texture = enemyAssets[1];
    else
      texture = enemyAssets[2];
    break;

  case EnemyType::SNIPER:
    if (currentEntityHP > totalEntityHP * 0.66f)
      texture = enemyAssets[3];
    else if (currentEntityHP > totalEntityHP * 0.33f)
      texture = enemyAssets[4];
    else
      texture = enemyAssets[5];
    break;
  default:
    break;
  }

  if (texture) {
    AssetSystem::instance().drawTexture(texture, position.x, position.y);
  }

  DrawText(TextFormat("%d / %d", currentEntityHP, totalEntityHP),
           position.x + 20, position.y - 20, 10, BLACK);
}
