#pragma once

#include "Projectile.hpp"
#include <raylib.h>

class LongRange : public Projectile {
public:
  LongRange(Faction f, Vector2 startPos, Vector2 dir)
      : Projectile(
            f, ProjectileType::LONGRANGE,
            {startPos, dir, {dir.x * 440.0f, dir.y * 440.0f}, 7, 5.0f, 5}) {}

  void draw() const override {
    DrawCircleV(position, size, PURPLE);
    DrawCircleV(position, 3, GREEN);
  }
};
