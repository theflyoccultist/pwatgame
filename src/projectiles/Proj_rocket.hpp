#pragma once

#include "Projectile.hpp"
#include <raylib.h>

class Rocket : public Projectile {
public:
  Rocket() : Projectile(Faction::None, ProjectileType::ROCKET) {}

  void draw() const override { DrawCircleV(stats.pos, stats.size, RED); }
};
