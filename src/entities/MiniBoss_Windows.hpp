#pragma once

#include "MiniBoss.hpp"
#include <array>
#include <cmath>
#include <iostream>
#include <raylib.h>

class Windows : public MiniBoss {
public:
  Windows(Vector2 pos, std::array<Texture2D *, 3> textures)
      : MiniBoss(BossType::WINDOWS, pos, {180.0f, 2600}, textures) {}

  void update(float dt, Vector2 playerPos) override {
    bossTimer += dt;
    position = {position.x, position.y + (sinf(bossTimer) * .25f)};

    if (bossTimer >= 10.0f && bossTimer <= 20.0f) {
      if (currentHP <= totalHP)
        currentHP += 1;
    } else if (bossTimer >= 20.0f) {
      std::cout << "Phase 3\n";
    }
  }

private:
  float bossTimer = 0.0f;
};
