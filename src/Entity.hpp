#include "Game.hpp"
#include <cmath>
#include <random>
#include <raylib.h>
#include <vector>

enum class EntityTypes { ALLY, ENEMY, NPC };

using std::vector;

class EntityManager {
public:
  struct EntityState {
    EntityTypes type;
    Vector2 position;
    Vector2 direction;
    bool active = true;
    int entityHP;
    float entitySpeed;
    int entitySize;
  };

private:
  vector<EntityState> enemies;

public:
  void spawnEnemies() {
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
                         {7, 1},
                         true,
                         hpDist(gen),
                         speedDist(gen),
                         60});
    }
  }

  void updateEnemies(const vector<Vector2> &bulletPositions,
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

    std::erase_if(enemies, [](const EntityState &e) { return !e.active; });
  }

  void drawEnemies() {
    for (auto &enemy : enemies) {
      Color enemyColor = (enemy.entityHP > 200) ? DARKGRAY : RED;
      DrawRectangle(enemy.position.x, enemy.position.y, enemy.entitySize,
                    enemy.entitySize, enemyColor);
      DrawText(TextFormat("%d", enemy.entityHP), enemy.position.x + 20,
               enemy.position.y - 20, 10, BLACK);
    }
  }

  bool checkPlayerInteraction(Vector2 playerPos, const EntityState &entity) {

    Rectangle playerRect = {playerPos.x, playerPos.y, 70, 70};
    Rectangle entityRect = {entity.position.x, entity.position.y, 50, 50};

    return CheckCollisionRecs(playerRect, entityRect);
  }

  const vector<EntityState> &getEnemies() const { return enemies; }

  bool checkBulletInteraction(Vector2 bulletPos, const EntityState &entity,
                              float entitySize = 60.0f,
                              float bulletSize = 10.0f) {

    Rectangle bulletRect = {bulletPos.x, bulletPos.y, bulletSize, bulletSize};
    Rectangle entityRect = {entity.position.x, entity.position.y, entitySize,
                            entitySize};

    return CheckCollisionRecs(bulletRect, entityRect);
  }
};
