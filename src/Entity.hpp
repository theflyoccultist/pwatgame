#include "Game.hpp"
#include <raylib.h>
#include <vector>

using std::vector;

class Entity {
  enum class EntityTypes { ALLY, ENEMY, NPC };

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
  }

  void updateEnemies(vector<EntityState> enemies) {
    for (auto &enemy : enemies) {
      enemy.position.x +=
          enemy.direction.x * enemy.entitySpeed * Game::deltaTime;
    }
  }

  void drawEnemies(Vector2 enemyPosition, int type) {
    DrawRectangle(700, 100, 100, 100, BLUE);
    DrawRectangle(650, 200, 100, 100, BLUE);
  }

  bool checkPlayerInteraction(Vector2 playerPos, const EntityState &entity,
                              float entitySize = 100.0f) {

    Rectangle playerRect = {playerPos.x, playerPos.y, 70, 70};
    Rectangle entityRect = {entity.position.x, entity.position.y, 100, 100};

    return CheckCollisionRecs(playerRect, entityRect);
  }
};
