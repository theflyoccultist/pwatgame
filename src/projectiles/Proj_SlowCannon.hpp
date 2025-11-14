#pragma once

#include "Projectile.hpp"
#include <raylib.h>

class SlowCannon : public Projectile {
public:
  SlowCannon(Faction f, Vector2 startPos, Vector2 dir)
      : Projectile(
            f, ProjectileType::SLOWCANNON,
            {startPos, dir, {dir.x * 150.0f, dir.y * 100.0f}, 20, 8.0f, 15}) {}

  void draw() const override {
    DrawCircleV(position, size, PURPLE);
    DrawCircleV(position, 4, GREEN);
  }
};
