#pragma once

#include "Projectile.hpp"
#include <raylib.h>

class LongRange : public Projectile {
public:
  LongRange(Vector2 startPos, Vector2 dir)
      : Projectile(ProjectileType::LONGRANGE, startPos, dir, LRSpeed,
                   {dir.x * LRSpeed, dir.y * LRSpeed}, LRSize, LRLifeTime) {}

  void update(float dt) override {
    position.x += velocity.x * dt;
    position.y += velocity.y * dt;
    lifetime -= dt;
  }

  void draw() const override {
    DrawCircleV(position, size, PURPLE);
    DrawCircleV(position, 3, GREEN);
  }

private:
  static constexpr float LRSpeed = 1400.0f;
  static constexpr int LRSize = 7;
  static constexpr float LRLifeTime = 1.0f;
};
