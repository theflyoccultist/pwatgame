#include "Enemy.hpp"
#include <array>
#include <cmath>
#include <raylib.h>

class Monitor : public Enemy {
public:
  static std::array<Texture2D *, 3> sharedTextures;
  Monitor() : Enemy(EnemyType::MONITOR, sharedTextures) {}

  void setTexture() override { textures = sharedTextures; }

  void update(ShootParams &p, [[maybe_unused]] ProjectileManager &projMan,
              float actorCooldown) override {

    if (actorCooldown >= 2.0f) {
      stats.pos.x -= std::cosf(actorCooldown) * stats.speed * p.dt;
      stats.pos.y -= std::sinf(actorCooldown) * stats.speed * p.dt;
    }

    if (stats.pos.x >= 1000.0f || stats.pos.y >= 1000.0f) {
      resetPosition();
    }
  }

  void resetPosition() { stats.pos = stats.initialPos; }
};
