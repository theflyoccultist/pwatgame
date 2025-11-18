#pragma once

#include "MiniBoss.hpp"
#include <array>
#include <cmath>
#include <raylib.h>

class Windows : public MiniBoss {
public:
  Windows(Vector2 pos, std::array<Texture2D *, 3> textures)
      : MiniBoss(BossType::WINDOWS, pos, {0.0f, 1600}, textures) {}

  void update(float dt, [[maybe_unused]] Vector2 playerPos) override {
    bossTimer += dt;
    position = {position.x, position.y + (sinf(bossTimer) * .25f)};
  }

private:
  float bossTimer = 0.0f;
};
