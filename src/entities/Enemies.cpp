#include "../Game.hpp"
#include "EntityManager.hpp"
#include <cmath>
#include <random>

vector<EntityManager::EntityState> enemies;

void EntityManager::spawnEnemies() {
  enemies.clear();

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<float> posDist(0.0f, 730.0f);
  std::uniform_int_distribution<> hpDist(10, 300);
  std::uniform_real_distribution<float> speedDist(1.0f, 30.0f);

  for (int i = 0; i < 20; ++i) {
    Vector2 pos = {posDist(gen), posDist(gen)};
    enemies.push_back({EntityTypes::ENEMY,
                       pos,
                       {0, 0},
                       true,
                       hpDist(gen),
                       speedDist(gen),
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
    Color enemyColor = (enemy.entityHP > 200) ? DARKGRAY : RED;
    DrawRectangle(enemy.position.x, enemy.position.y, enemy.entitySize,
                  enemy.entitySize, enemyColor);
    DrawText(TextFormat("%d", enemy.entityHP), enemy.position.x + 20,
             enemy.position.y - 20, 10, BLACK);
  }
}
