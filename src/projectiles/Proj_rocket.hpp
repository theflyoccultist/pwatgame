#pragma once

#include "Projectile.hpp"
#include <raylib.h>

class Rocket : public Projectile {
public:
  Rocket(Faction f, Vector2 startPos, Vector2 dir)
      : Projectile(
            f, ProjectileType::STRAIGHT,
            {startPos, dir, {dir.x * 800.0f, dir.y * 800.0f}, 45, 5.0f, 55}) {}

  void draw() const override {
    DrawCircleV(position, size, RED);
    DrawCircleV(position, 15, BLACK);
  }
};
