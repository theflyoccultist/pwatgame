#pragma once

#include "Enemy.hpp"
#include <array>
#include <cmath>
#include <raylib.h>

class Sniper : public Enemy {
public:
  Sniper(Vector2 pos, std::array<Texture2D *, 3> textures)
      : Enemy(EnemyType::SNIPER, pos, Random::rangeFloat(10, 20),
              Random::rangeInt(150, 250), textures) {}

  void update(float delta, Vector2 playerPos) override {
    if (std::sqrt(std::pow(position.x - playerPos.x, 2) +
                  std::pow(position.y - playerPos.y, 2)) < 200)
      position.x -= speed * delta;
  }
};
