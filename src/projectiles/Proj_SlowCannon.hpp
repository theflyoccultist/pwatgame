#pragma once

#include "Projectile.hpp"
#include <raylib.h>

class SlowCannon : public Projectile {
public:
  SlowCannon() : Projectile(Faction::None, ProjectileType::SLOWCANNON) {}

  void reset(Faction f, Vector2 pos, Vector2 dir) {
    stats.active = true;
    faction = f;
    stats.pos = pos;
    stats.dir = dir;
    stats.vel = {dir.x * 150.0f, dir.y * 100.0f};
    stats.size = 20.0f;
    stats.lifetime = 8.0f;
    stats.damage = 15;
  }

  void draw() const override {
    DrawCircleV(stats.pos, stats.size, PURPLE);
    DrawCircleV(stats.pos, 4, GREEN);
  }
};
