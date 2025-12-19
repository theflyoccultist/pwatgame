
#pragma once

#include "../utils/clampEntities.hpp"
#include "MiniBoss.hpp"
#include <array>
#include <cmath>
#include <raylib.h>

class Lisp : public MiniBoss {
public:
  static std::array<Texture2D *, 3> sharedTextures;
  Lisp() : MiniBoss(MiniBossType::LISP, sharedTextures) {}

  void setTexture() override { textures = sharedTextures; }

  void update(ShootParams &p, ProjectileManager &projMan,
              float bossCooldown) override {
    stats.pos = {stats.pos.x, stats.pos.y + (sinf(bossCooldown) * .25f)};

    if (bossCooldown <= 4.0f) {
      copyPlayerMovements(p.playerPos);
    } else {
      backToCenter(p.dt);
    }
  }

private:
  void copyPlayerMovements(Vector2 playerPos) {
    stats.pos = {playerPos.x + 100.0f, playerPos.y + 100.0f};
    ClampEntities::clamp(stats.pos, (int)stats.size);
  }

  void backToCenter(float dt) {
    Vector2 dir = {320.0f - stats.pos.x, 320.0f - stats.pos.y};

    float length = std::sqrtf(dir.x * dir.x + dir.y * dir.y);
    if (length > 0.0f) {
      dir.x /= length;
      dir.y /= length;
    }

    stats.pos.x += dir.x * stats.speed * dt;
    stats.pos.y += dir.y * stats.speed * dt;
  }
};
