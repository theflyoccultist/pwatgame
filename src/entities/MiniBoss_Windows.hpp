#pragma once

#include "MiniBoss.hpp"
#include <array>
#include <cmath>
#include <raylib.h>

class Windows : public MiniBoss {
public:
  static std::array<Texture2D *, 3> sharedTextures;
  Windows() : MiniBoss(MiniBossType::WINDOWS, sharedTextures) {}

  void setTexture() override { textures = sharedTextures; }

  void update(float dt, Vector2 playerPos) override {
    bossTimer += dt;
    stats.pos = {stats.pos.x, stats.pos.y + (sinf(bossTimer) * .25f)};

    float bossCooldown = std::fmodf(bossTimer, 8.0f);

    if (bossCooldown >= 0.0f && bossCooldown <= 4.0f) {
      moveTowardsPlayer(dt, playerPos);
    } else {
      if (stats.currentHP <= stats.totalHP)
        stats.currentHP++;
    }
  }

private:
  float bossTimer = 0.0f;

  void moveTowardsPlayer(float dt, Vector2 playerPos) {
    Vector2 dir = {playerPos.x - stats.pos.x, playerPos.y - stats.pos.y};

    float length = std::sqrtf(dir.x * dir.x + dir.y * dir.y);
    if (length > 0.0f) {
      dir.x /= length;
      dir.y /= length;
    }

    stats.pos.x += dir.x * stats.speed * dt;
    stats.pos.y += dir.y * stats.speed * dt;
  }
};
