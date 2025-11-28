
#pragma once

#include "MiniBoss.hpp"
#include <array>
#include <cmath>
#include <iostream>
#include <raylib.h>

class Lisp : public MiniBoss {
public:
  static std::array<Texture2D *, 3> sharedTextures;
  Lisp() : MiniBoss(MiniBossType::LISP, sharedTextures) {}

  void setTexture() override { textures = sharedTextures; }

  void update(float dt, [[maybe_unused]] Vector2 playerPos) override {
    bossTimer += dt;
    stats.pos = {stats.pos.x, stats.pos.y + (sinf(bossTimer) * .25f)};

    if (bossTimer >= 10.0f && bossTimer <= 20.0f) {
      if (stats.currentHP <= stats.totalHP)
        stats.currentHP -= 30;
    } else if (bossTimer >= 20.0f) {
      std::cout << "MiniBoss Lisp : Phase 3\n";
    }
  }

private:
  float bossTimer = 0.0f;
};
