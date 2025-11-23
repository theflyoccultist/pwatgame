#pragma once

#include "Projectile.hpp"
#include <raylib.h>

class Uzi : public Projectile {
public:
  Uzi() : Projectile(Faction::None, ProjectileType::UZI) {}

  static constexpr float spread = 5.0f;

  void reset(Faction f, Vector2 pos, Vector2 dir) {
    stats.active = true;
    faction = f;
    stats.pos = pos;
    stats.dir = dir;
    stats.vel = {dir.x * 750.0f, dir.y * 750.0f};
    stats.size = 5.0f;
    stats.lifetime = 2.0f;
    stats.damage = 5;
  }

  void draw() const override { DrawCircleV(stats.pos, stats.size, RED); }
};
