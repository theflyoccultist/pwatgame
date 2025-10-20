#include "Game.hpp"
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
  };

private:
  vector<EntityState> enemies;

public:
  void spawnEnemies() {
    enemies.clear();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> hpDist(10, 300);
    std::uniform_real_distribution<float> posDist(0.0f, 730.0f);

    for (int i = 0; i < 10; ++i) {
      Vector2 pos = {posDist(gen), posDist(gen)};
      enemies.push_back(
          {EntityTypes::ENEMY, pos, {0, 0}, true, hpDist(gen), 0});
    }
  }

  void updateEnemies(const vector<Vector2> &bulletPositions) {
    for (auto &enemy : enemies) {
      enemy.position.x +=
          enemy.direction.x * enemy.entitySpeed * Game::deltaTime;
      enemy.position.y +=
          enemy.direction.y * enemy.entitySpeed * Game::deltaTime;

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
      DrawRectangle(enemy.position.x, enemy.position.y, 100, 100, enemyColor);
      DrawText(TextFormat("%d", enemy.entityHP), enemy.position.x + 20,
               enemy.position.y - 20, 10, BLACK);
    }
  }

  bool checkPlayerInteraction(Vector2 playerPos, const EntityState &entity,
                              float entitySize = 100.0f) {

    Rectangle playerRect = {playerPos.x, playerPos.y, 70, 70};
    Rectangle entityRect = {entity.position.x, entity.position.y, entitySize,
                            entitySize};

    return CheckCollisionRecs(playerRect, entityRect);
  }

  const vector<EntityState> &getEnemies() const { return enemies; }

  bool checkBulletInteraction(Vector2 bulletPos, const EntityState &entity,
                              float entitySize = 100.0f,
                              float bulletSize = 5.0f) {

    Rectangle bulletRect = {bulletPos.x, bulletPos.y, bulletSize, bulletSize};
    Rectangle entityRect = {entity.position.x, entity.position.y, entitySize,
                            entitySize};

    return CheckCollisionRecs(bulletRect, entityRect);
  }
};
