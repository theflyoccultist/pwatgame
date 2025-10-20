#include <raylib.h>

#include <vector>

using std::vector;

enum class EntityTypes { ALLY, ENEMY, NPC };

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

public:
  void spawnEnemies();
  void updateEnemies(const vector<Vector2> &bulletPositions, Vector2 playerPos);
  void drawEnemies();
};
