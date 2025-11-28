#include "Enemy.hpp"
#include <array>
#include <cmath>
#include <raylib.h>

class Monitor : public Enemy {
public:
  static std::array<Texture2D *, 3> sharedTextures;
  Monitor() : Enemy(EnemyType::MONITOR, sharedTextures) {}

  void setTexture() override { textures = sharedTextures; }

  void update(float delta, [[maybe_unused]] Vector2 playerPos) override {
    timer += delta;

    stats.pos.x = std::cosf(timer) * stats.speed + 400;
    stats.pos.y = std::sinf(timer) * stats.speed + 400;
  }

private:
  float timer = 0;
};
