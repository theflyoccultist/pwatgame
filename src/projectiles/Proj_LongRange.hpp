#pragma once

#include "Projectile.hpp"
#include <raylib.h>

class LongRange : public Projectile {
public:
  LongRange() : Projectile(Faction::None, ProjectileType::LONGRANGE) {}

  void draw() const override {
    DrawCircleV(stats.pos, (float)stats.size, PURPLE);
    DrawCircleV(stats.pos, 3, GREEN);
  }
};
