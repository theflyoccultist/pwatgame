#pragma once

#include "../utils/Random.hpp"
#include "Enemy.hpp"
#include <array>
#include <cmath>
#include <raylib.h>

class Sniper : public Enemy {
public:
  Sniper(Vector2 pos, std::array<Texture2D *, 3> textures)
      : Enemy(EnemyType::SNIPER, pos,
              {Random::rangeFloat(10, 20), Random::rangeInt(40, 70)},
              textures) {}

  void update(float delta, Vector2 playerPos) override {
    float dist = std::sqrtf(std::powf(playerPos.x - position.x, 2) +
                            std::powf(playerPos.y - position.y, 2));

    if (dist < 300) {
      Vector2 dir = {position.x - playerPos.x, position.y - playerPos.y};
      float len = std::sqrtf(dir.x * dir.x + dir.y * dir.y);

      if (len > 0.0001f) {
        dir.x /= len;
        dir.y /= len;
      }

      position.x += dir.x * speed * delta * 8;
      position.y += dir.y * speed * delta * 8;
    }
    ClampEntities::clamp(position, 60);
  }
};
