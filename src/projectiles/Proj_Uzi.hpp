#pragma once

#include "Projectile.hpp"
#include <raylib.h>

class Uzi : public Projectile {
public:
  Uzi() : Projectile(Faction::None, ProjectileType::UZI) {}

  void draw() const override { DrawCircleV(stats.pos, (float)stats.size, RED); }
};
