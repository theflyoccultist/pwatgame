#pragma once

#include "Projectile.hpp"
#include <raylib.h>

class SlowCannon : public Projectile {
public:
  SlowCannon() : Projectile(Faction::None, ProjectileType::SLOWCANNON) {}

  void draw() const override {
    DrawCircleV(stats.pos, (float)stats.size, PURPLE);
  }
};
