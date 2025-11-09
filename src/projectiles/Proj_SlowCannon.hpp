#pragma once

#include "Projectile.hpp"
#include <raylib.h>

class SlowCannon : public Projectile {
public:
  SlowCannon(Faction f, Vector2 startPos, Vector2 dir)
      : Projectile(f, ProjectileType::SLOWCANNON, startPos, dir, cSpeed,
                   {dir.x * cSpeed, dir.y * cSpeed}, cSize, cLifetime,
                   cDamage) {}

  void update(float dt) override {
    position.x += velocity.x * dt;
    position.y += velocity.y * dt;
    lifetime -= dt;
  };

  void draw() const override {
    DrawCircleV(position, size, PURPLE);
    DrawCircleV(position, 4, GREEN);
  }

private:
  static constexpr float cSpeed = 100.0f;
  static constexpr int cSize = 20;
  static constexpr float cLifetime = 8.0f;
  static constexpr int cDamage = 15;
};
