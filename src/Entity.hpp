#include "Game.hpp"
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
    int enityHP;
    float entitySpeed;
  };

private:
  vector<EntityState> enemies;

public:
  void spawnEnemies() {
    enemies.push_back({(EntityTypes::ENEMY), {400, 200}, {0, 0}, 30, 120.0f});
    enemies.push_back({(EntityTypes::ENEMY), {680, 300}, {0, 0}, 500, 90.0f});
  }

  void updateEnemies() {
    for (auto &enemy : enemies) {
      enemy.position.x +=
          enemy.direction.x * enemy.entitySpeed * Game::deltaTime;
      enemy.position.y +=
          enemy.direction.y * enemy.entitySpeed * Game::deltaTime;
    }
  }

  void drawEnemies() {
    for (auto &enemy : enemies) {
      DrawRectangleV(enemy.position, {100, 100}, BLUE);
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
};
