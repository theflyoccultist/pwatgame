#pragma once

#include "Projectile.hpp"
#include <raylib.h>

class Straight : public Projectile {
public:
  Straight(Faction f, Vector2 startPos, Vector2 dir)
      : Projectile(
            f, ProjectileType::STRAIGHT,
            {startPos, dir, {dir.x * 650.0f, dir.y * 650.0f}, 10, 2.0f, 7}) {}

  void draw() const override {
    DrawCircleV(position, size, BLUE);
    DrawCircleV(position, 4, RED);
  }
};
