#pragma once

#include "../utils/Random.hpp"
#include "Enemy.hpp"
#include <array>
#include <raylib.h>

class Zomb : public Enemy {
public:
  static std::array<Texture2D *, 3> sharedTextures;
  Zomb() : Enemy(EnemyType::ZOMB, sharedTextures) {}

  void reset(Vector2 pos) {
    stats.active = true;
    stats.pos = pos;
    stats.speed = 150;
    stats.totalHP = Random::rangeInt(40, 70);
    stats.currentHP = stats.totalHP;

    textures = sharedTextures;
  }

  void update(float delta, [[maybe_unused]] Vector2 playerPos) override {
    if (isX) {
      stats.pos.x += stats.speed * delta * dirX;
      if (stats.pos.x >= 730.f)
        dirX = -1;
      else if (stats.pos.x <= 0)
        dirX = 1;
    } else {
      stats.pos.y += stats.speed * delta * dirY;
      if (stats.pos.y >= 730.f)
        dirY = -1;
      else if (stats.pos.y <= 0)
        dirY = 1;
    }
  }

private:
  float dirX = 1;
  float dirY = 1;
  const bool isX = Random::chance(.5f);
};
