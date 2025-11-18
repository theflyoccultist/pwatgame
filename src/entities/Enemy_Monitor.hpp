#include "Enemy.hpp"
#include <array>
#include <cmath>
#include <raylib.h>

class Gost : public Enemy {
public:
  Gost(Vector2 pos, std::array<Texture2D *, 3> textures)
      : Enemy(EnemyType::MONITOR, pos, {200, Random::rangeInt(60, 200)},
              textures) {}

  void update(float delta, [[maybe_unused]] Vector2 playerPos) override {
    timer += delta;

    position.x = std::cosf(timer) * speed + 400;
    position.y = std::sinf(timer) * speed + 400;
  }

private:
  float timer = 0;
};
