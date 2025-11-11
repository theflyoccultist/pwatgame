#pragma once

#include "Projectile.hpp"
#include <raylib.h>

class Straight : public Projectile {
public:
  Straight(Faction f, Vector2 startPos, Vector2 dir)
      : Projectile(f, ProjectileType::STRAIGHT, startPos, dir, sSpeed,
                   {dir.x * sSpeed, dir.y * sSpeed}, sSize, sLifetime,
                   sDamage) {}

  void draw() const override {
    DrawCircleV(position, size, BLUE);
    DrawCircleV(position, 4, RED);
  }

private:
  static constexpr float sSpeed = 650.0f;
  static constexpr int sSize = 10;
  static constexpr float sLifetime = 2.0f;
  static constexpr int sDamage = 7;
};
