#pragma once

#include "Projectile.hpp"
#include <raylib.h>

class Rocket : public Projectile {
public:
  Rocket(Faction f, Vector2 startPos, Vector2 dir)
      : Projectile(f, ProjectileType::STRAIGHT,
                   {startPos,
                    dir,
                    rSpeed,
                    {dir.x * rSpeed, dir.y * rSpeed},
                    rSize,
                    rLifetime,
                    rDamage}) {}

  void update(float dt) override {
    position.x += velocity.x * dt;
    position.y += velocity.y * dt;
    lifetime -= dt;
  };

  void draw() const override {
    DrawCircleV(position, size, RED);
    DrawCircleV(position, 15, BLACK);
  }

private:
  static constexpr float rSpeed = 800.0f;
  static constexpr int rSize = 50;
  static constexpr float rLifetime = 5.0f;
  static constexpr int rDamage = 65;
};
