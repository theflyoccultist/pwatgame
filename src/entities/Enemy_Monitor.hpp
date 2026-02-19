#pragma once

#include <entities/Enemy.hpp>

class Monitor : public Enemy {
public:
  static std::array<Texture2D *, 3> sharedTextures;
  Monitor() : Enemy(EnemyType::MONITOR, sharedTextures) {}

  void setTexture() override { textures = sharedTextures; }

  void update(ShootParams &p, [[maybe_unused]] ProjectileManager &projMan,
              float actorCooldown) override {
    float monitorCooldown = std::fmodf(actorCooldown, 4.0f);

    if (monitorCooldown >= 2.0f) {
      stats.pos.x -= std::cosf(monitorCooldown) * stats.speed * p.dt;
      stats.pos.y -= std::sinf(monitorCooldown) * stats.speed * p.dt;
    }

    if (stats.pos.x >= 1000.0f || stats.pos.y >= 1000.0f) {
      resetPosition();
    }
  }

private:
  void resetPosition() { stats.pos = stats.initialPos; }
};
