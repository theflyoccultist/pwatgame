#include <raylib.h>
#include <vector>

using std::vector;

enum class EnemyType { SWARMER, SNIPER, COUNT };

class Enemy {
public:
  EnemyType type;
  Vector2 position;
  Vector2 direction;
  bool active = true;
  int totalEntityHP;
  int currentEntityHP;
  float entitySpeed;
  float entitySize;

  void draw() const;
};

class EnemyManager {
public:
  static inline size_t enemiesCount = 0;

  void clearEnemies();
  void spawnEnemies(EnemyType type, size_t count);
  void updateEnemies(float deltaTime, const vector<Vector2> &bulletPositions,
                     Vector2 playerPos);
  void drawAll();
};
