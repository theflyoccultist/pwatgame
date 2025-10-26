#pragma once

#include "Projectile.hpp"
#include <raylib.h>

class StraightProjectile : public Projectile {
public:
  StraightProjectile(Vector2 startPos, Vector2 dir)
      : Projectile(ProjectileType::STRAIGHT, startPos, dir, straightSpeed,
                   {dir.x * straightSpeed, dir.y * straightSpeed}, straightSize,
                   straightLifetime) {}

  void update(float dt) override {
    position.x += velocity.x * dt;
    position.y += velocity.y * dt;
    lifetime -= dt;
  };

  void draw() const override {
    DrawCircleV(position, size, BLUE);
    DrawCircleV(position, 4, RED);
  }

private:
  static constexpr float straightSpeed = 700.0f;
  static constexpr int straightSize = 10;
  static constexpr float straightLifetime = 2.0f;
};
