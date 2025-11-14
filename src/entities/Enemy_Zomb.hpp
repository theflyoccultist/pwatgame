#pragma once

#include "../utils/Random.hpp"
#include "Enemy.hpp"
#include <array>
#include <raylib.h>

class Zomb : public Enemy {
public:
  Zomb(Vector2 pos, std::array<Texture2D *, 3> textures)
      : Enemy(EnemyType::ZOMB, pos, {150, Random::rangeInt(40, 70)}, textures) {
  }

  void update(float delta, [[maybe_unused]] Vector2 playerPos) override {
    if (isX) {
      position.x += speed * delta * dirX;
      if (position.x >= 730.f)
        dirX = -1;
      else if (position.x <= 0)
        dirX = 1;
    } else {
      position.y += speed * delta * dirY;
      if (position.y >= 730.f)
        dirY = -1;
      else if (position.y <= 0)
        dirY = 1;
    }
  }

private:
  float dirX = 1;
  float dirY = 1;
  const bool isX = Random::chance(.5f);
};
