#pragma once

#include "../utils/clampEntities.hpp"
#include "Enemy.hpp"
#include <array>
#include <cmath>
#include <raylib.h>

class Sniper : public Enemy {
public:
  static std::array<Texture2D *, 3> sharedTextures;
  Sniper() : Enemy(EnemyType::SNIPER, sharedTextures) {}

  void setTexture() override { textures = sharedTextures; }

  void update(float delta, Vector2 playerPos) override {
    float dist = std::sqrtf(std::powf(playerPos.x - stats.pos.x, 2) +
                            std::powf(playerPos.y - stats.pos.y, 2));

    if (dist < 300) {
      Vector2 dir = {stats.pos.x - playerPos.x, stats.pos.y - playerPos.y};
      float len = std::sqrtf(dir.x * dir.x + dir.y * dir.y);

      if (len > 0.0001f) {
        dir.x /= len;
        dir.y /= len;
      }

      stats.pos.x += dir.x * stats.speed * delta;
      stats.pos.y += dir.y * stats.speed * delta;
    }
    ClampEntities::clamp(stats.pos, 60);
  }
};
