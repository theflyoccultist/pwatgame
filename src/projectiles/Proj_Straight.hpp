#pragma once

#include "Projectile.hpp"
#include <raylib.h>

class Straight : public Projectile {
public:
  Straight() : Projectile(Faction::None, ProjectileType::STRAIGHT) {}

  void draw() const override {
    DrawCircleV(stats.pos, (float)stats.size, BLUE);
  }
};
