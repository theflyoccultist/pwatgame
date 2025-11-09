#pragma once

#include "../utils/Random.hpp"
#include "Enemy.hpp"
#include <array>
#include <raylib.h>

class Swarmer : public Enemy {
public:
  Swarmer(Vector2 pos, std::array<Texture2D *, 3> textures)
      : Enemy(EnemyType::SWARMER, pos, Random::rangeFloat(60, 120),
              Random::rangeInt(40, 70), 70, textures) {}

  void update(float delta, Vector2 playerPos) override {
    Vector2 dir = {playerPos.x - position.x, playerPos.y - position.y};

    float length = std::sqrt(dir.x * dir.x + dir.y * dir.y);
    if (length > 0.0f) {
      dir.x /= length;
      dir.y /= length;
    }

    position.x += dir.x * speed * delta;
    position.y += dir.y * speed * delta;
  };
};
