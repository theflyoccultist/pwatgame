#pragma once

#include "../utils/Random.hpp"
#include "Enemy.hpp"
#include <array>
#include <raylib.h>

class Swarmer : public Enemy {
public:
  static std::array<Texture2D *, 3> sharedTextures;
  Swarmer() : Enemy(EnemyType::SWARMER, sharedTextures) {}

  void reset(Vector2 pos) {
    stats.active = true;
    stats.pos = pos;
    stats.speed = Random::rangeFloat(60, 120);
    stats.totalHP = Random::rangeInt(28, 60);
    stats.currentHP = stats.totalHP;

    textures = sharedTextures;
  }

  void update(float delta, Vector2 playerPos) override {
    Vector2 dir = {playerPos.x - stats.pos.x, playerPos.y - stats.pos.y};

    float length = std::sqrtf(dir.x * dir.x + dir.y * dir.y);
    if (length > 0.0f) {
      dir.x /= length;
      dir.y /= length;
    }

    stats.pos.x += dir.x * stats.speed * delta;
    stats.pos.y += dir.y * stats.speed * delta;
  };
};
