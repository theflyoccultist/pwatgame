
#pragma once

#include "MiniBoss.hpp"
#include <array>
#include <cmath>
#include <iostream>
#include <raylib.h>

class Lisp : public MiniBoss {
public:
  Lisp(Vector2 pos, std::array<Texture2D *, 3> textures)
      : MiniBoss(MiniBossType::LISP, pos, {180.0f, 2600}, textures) {}

  void update(float dt, [[maybe_unused]] Vector2 playerPos) override {
    bossTimer += dt;
    position = {position.x, position.y + (sinf(bossTimer) * .25f)};

    if (bossTimer >= 10.0f && bossTimer <= 20.0f) {
      if (currentHP <= totalHP)
        currentHP -= 30;
    } else if (bossTimer >= 20.0f) {
      std::cout << "MiniBoss Lisp : Phase 3\n";
    }
  }

private:
  float bossTimer = 0.0f;
};
