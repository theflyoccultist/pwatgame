#pragma once

#include "Projectile.hpp"

class Grenade : public Projectile {
public:
  Grenade() : Projectile(Faction::None, ProjectileType::GRENADE) {}

  void draw() const override {
    DrawCircleV(stats.pos, (float)stats.size, ORANGE);
  }
};
