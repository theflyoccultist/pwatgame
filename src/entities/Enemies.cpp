#include "../Game.hpp"
#include "../Player.hpp"
#include "../sound/AudioSystem.hpp"
#include "../texture/AssetSystem.hpp"
#include "../utils/Random.hpp"
#include "EntityManager.hpp"
#include <array>
#include <cmath>
#include <cstddef>
#include <raylib.h>
#include <string>

vector<EntityManager::EntityState> enemies;
std::array<Texture2D *, 3> enemyAssets;

void EntityManager::spawnEnemies() {
  enemies.clear();
  enemiesCount = 60;

  int currentEnemyHP, totalEnemyHP;
  size_t e = enemiesCount;

  for (size_t i = 0; i < e; ++i) {
    Vector2 pos = {Random::rangeFloat(0.0f, 730.0f),
                   Random::rangeFloat(0.0f, 730.0f)};

    currentEnemyHP = totalEnemyHP = Random::rangeInt(120, 300);

    enemies.push_back({EntityTypes::ENEMY,
                       pos,
                       {0, 0},
                       true,
                       currentEnemyHP,
                       totalEnemyHP,
                       Random::rangeFloat(30.0f, 70.0f),
                       60});
  }

  const std::array<std::string, 3> enemyPaths = {
      "../assets/enemies/enemy_HIGH.png", "../assets/enemies/enemy_MED.png",
      "../assets/enemies/enemy_LOW.png"};

  for (size_t i = 0; i < enemyPaths.size(); ++i) {
    enemyAssets[i] =
        &AssetSystem::instance().loadTexture(enemyPaths[i], 60, 60);
  }
}

const vector<EntityManager::EntityState> &getEnemies() { return enemies; }

bool checkBulletInteraction(Vector2 bulletPos,
                            const EntityManager::EntityState &entity,
                            float entitySize = 60.0f,
                            float bulletSize = 10.0f) {

  Rectangle bulletRect = {bulletPos.x, bulletPos.y, bulletSize, bulletSize};
  Rectangle entityRect = {entity.position.x, entity.position.y, entitySize,
                          entitySize};

  return CheckCollisionRecs(bulletRect, entityRect);
}

bool checkPlayerInteraction(Vector2 playerPos,
                            const EntityManager::EntityState &entity) {

  Rectangle playerRect = {playerPos.x, playerPos.y, 70, 70};
  Rectangle entityRect = {entity.position.x, entity.position.y, 70, 70};

  return CheckCollisionRecs(playerRect, entityRect);
}

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

    if (enemy.active && checkPlayerInteraction(playerPos, enemy))
      if (PlayerState::damageCooldown <= 0.0f) {
        PlayerState::health--;
        PlayerState::damageCooldown = 0.15f;
      }

    for (auto &bulletPos : bulletPositions) {
      if (enemy.active && checkBulletInteraction(bulletPos, enemy)) {
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

  std::erase_if(enemies,
                [](const EntityManager::EntityState &e) { return !e.active; });
}

void EntityManager::drawEnemies() {
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

    DrawText(TextFormat("%d / %d", enemy.currentEntityHP, enemy.totalEntityHP),
             enemy.position.x + 20, enemy.position.y - 20, 10, BLACK);
  }
}
