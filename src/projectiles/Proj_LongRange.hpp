#pragma once

#include "Projectile.hpp"
#include <raylib.h>

class LongRange : public Projectile {
public:
  LongRange() : Projectile(Faction::None, ProjectileType::LONGRANGE) {}

  void reset(Faction f, Vector2 pos, Vector2 dir) {
    stats.active = true;
    faction = f;
    stats.pos = pos;
    stats.dir = dir;
    stats.vel = {dir.x * 440.0f, dir.y * 440.0f};
    stats.size = 7.0f;
    stats.lifetime = 5.0f;
    stats.damage = 5;
  }

  void draw() const override {
    DrawCircleV(stats.pos, stats.size, PURPLE);
    DrawCircleV(stats.pos, 3, GREEN);
  }
};
