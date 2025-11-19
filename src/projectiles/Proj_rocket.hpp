#pragma once

#include "Projectile.hpp"
#include <raylib.h>

class Rocket : public Projectile {
public:
  Rocket() : Projectile(Faction::None, ProjectileType::STRAIGHT) {}

  void reset(Faction f, Vector2 pos, Vector2 dir) {
    stats.active = true;
    faction = f;
    stats.pos = pos;
    stats.dir = dir;
    stats.vel = {dir.x * 800.0f, dir.y * 800.0f};
    stats.size = 25.0f;
    stats.lifetime = 5.0f;
    stats.damage = 55;
  }

  void draw() const override {
    DrawCircleV(stats.pos, stats.size, RED);
    DrawCircleV(stats.pos, 15, BLACK);
  }
};
