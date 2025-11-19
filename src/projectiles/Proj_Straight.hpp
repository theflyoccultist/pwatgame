#pragma once

#include "Projectile.hpp"
#include <raylib.h>

class Straight : public Projectile {
public:
  Straight() : Projectile(Faction::None, ProjectileType::STRAIGHT) {}

  void reset(Faction f, Vector2 pos, Vector2 dir) {
    stats.active = true;
    faction = f;
    stats.pos = pos;
    stats.dir = dir;
    stats.vel = {dir.x * 650.0f, dir.y * 650.0f};
    stats.size = 10.0f;
    stats.lifetime = 2.0f;
    stats.damage = 7;
  }

  void draw() const override {
    DrawCircleV(stats.pos, stats.size, BLUE);
    DrawCircleV(stats.pos, 4, RED);
  }
};
