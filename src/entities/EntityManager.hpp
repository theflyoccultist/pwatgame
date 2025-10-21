#include <raylib.h>

#include <vector>

using std::vector;

enum class EntityType { ENEMY, ALLY };

enum class EnemyType { SWARMER, SNIPER };

struct Entity {
  EntityType type;
  Vector2 position;
  Vector2 direction;
  bool active = true;
  int totalEntityHP;
  int currentEntityHP;
  float entitySpeed;
  int entitySize;
};

class EntityManager {
public:
  static inline size_t enemiesCount = 80;
  void spawnEnemies(EnemyType type, size_t count);
  void updateEnemies(const vector<Vector2> &bulletPositions, Vector2 playerPos);
  void drawEnemies();
};
