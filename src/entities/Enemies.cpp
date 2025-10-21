#include "../Game.hpp"
#include "../utils/Random.hpp"
#include "EntityManager.hpp"
#include <cmath>
#include <raylib.h>

vector<EntityManager::EntityState> enemies;

void EntityManager::spawnEnemies() {
  enemies.clear();

  for (int i = 0; i < 80; ++i) {
    Vector2 pos = {Random::rangeFloat(0.0f, 730.0f),
                   Random::rangeFloat(0.0f, 730.0f)};
    enemies.push_back({EntityTypes::ENEMY,
                       pos,
                       {0, 0},
                       true,
                       Random::rangeInt(10, 300),
                       Random::rangeFloat(20.0f, 40.0f),
                       60});
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

void EntityManager::updateEnemies(const vector<Vector2> &bulletPositions,
                                  Vector2 playerPos) {
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

    for (auto &bulletPos : bulletPositions) {
      if (enemy.active && checkBulletInteraction(bulletPos, enemy)) {
        enemy.entityHP--;
        if (enemy.entityHP <= 0) {
          enemy.active = false;
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

    Color enemyColor;
    if (enemy.entityHP > 200)
      enemyColor = DARKGRAY;
    else if (enemy.entityHP > 100)
      enemyColor = RED;
    else
      enemyColor = PURPLE;

    DrawRectangle(enemy.position.x, enemy.position.y, enemy.entitySize,
                  enemy.entitySize, enemyColor);
    DrawText(TextFormat("%d", enemy.entityHP), enemy.position.x + 20,
             enemy.position.y - 20, 10, BLACK);
  }
}
