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

  void update(float dt, Vector2 playerPos, float bossCooldown) override {
    stats.pos = {stats.pos.x, stats.pos.y + (sinf(bossCooldown) * .25f)};

    if (bossCooldown <= 2.0f) {
      moveTowardsPlayer(dt, playerPos);
    }
  }

private:
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
