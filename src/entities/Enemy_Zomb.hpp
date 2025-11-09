#pragma once

#include "../utils/Random.hpp"
#include "Enemy.hpp"
#include <array>
#include <raylib.h>

class Zomb : public Enemy {
public:
  Zomb(Vector2 pos, std::array<Texture2D *, 3> textures)
      : Enemy(EnemyType::ZOMB, pos, 150, Random::rangeInt(40, 70), 70,
              textures) {}

  int dir = 1;

  void update(float delta, Vector2 playerPos) override {
    position.x += speed * delta * dir;
    if (position.x >= 730.f)
      dir = -1;
    else if (position.x <= 0)
      dir = 1;
  }
};
