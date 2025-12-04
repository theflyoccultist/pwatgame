
#pragma once

#include "MiniBoss.hpp"
#include <array>
#include <cmath>
#include <raylib.h>

class Lisp : public MiniBoss {
public:
  static std::array<Texture2D *, 3> sharedTextures;
  Lisp() : MiniBoss(MiniBossType::LISP, sharedTextures) {}

  void setTexture() override { textures = sharedTextures; }

  void update(float dt, Vector2 playerPos, float bossCooldown) override {
    stats.pos = {stats.pos.x, stats.pos.y + (sinf(bossCooldown) * .25f)};

    if (bossCooldown >= 4.0f && bossCooldown <= 8.0f) {
      stats.currentHP -= 30;
    }
  }
};
