#include "Enemy.hpp"
#include <array>
#include <cmath>
#include <raylib.h>

class Miku : public Enemy {
public:
  static std::array<Texture2D *, 3> sharedTextures;
  Miku() : Enemy(EnemyType::MIKU, sharedTextures) {}

  void setTexture() override { textures = sharedTextures; }

  void update(ShootParams &p, [[maybe_unused]] ProjectileManager &projMan,
              float actorCooldown) override {

    if (actorCooldown >= 2.0f) {
      stats.pos.x -= std::cosf(actorCooldown) * stats.speed * p.dt;
      stats.pos.y -= std::sinf(actorCooldown) * stats.speed * p.dt;
    }
  }

private:
  void moveAccrossScreen(float actorCooldown) {
    if (actorCooldown <= 1.0f ||
        (actorCooldown >= 8.0f && actorCooldown <= 9.0f)) {
      stats.pos.x +=
          ((float)GetScreenHeight() - stats.size - stats.pos.x) * 0.25f;
      stats.pos.y +=
          ((float)GetScreenWidth() - stats.size - stats.pos.y) * 0.25f;
    }

    else if (actorCooldown <= 2.0f ||
             (actorCooldown >= 9.0f && actorCooldown <= 10.0f)) {
      stats.pos.x += (0 - stats.pos.x) * 0.25f;
      stats.pos.y +=
          ((float)GetScreenWidth() - stats.size - stats.pos.y) * 0.25f;
    }

    else if (actorCooldown <= 3.0f ||
             (actorCooldown >= 10.0f && actorCooldown <= 11.0f)) {
      stats.pos.x +=
          ((float)GetScreenHeight() - stats.size - stats.pos.x) * 0.25f;
      stats.pos.y += (0 - stats.pos.y) * 0.25f;
    }

    else if (actorCooldown <= 4.0f ||
             (actorCooldown >= 11.0f && actorCooldown <= 12.0f)) {
      stats.pos.x += (0 - stats.pos.x) * 0.25f;
      stats.pos.y += (0 - stats.pos.y) * 0.25f;
    }
  }
};
