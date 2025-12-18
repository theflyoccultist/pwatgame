#pragma once

#include "Projectile.hpp"

class Hellfire : public Projectile {
public:
  Hellfire() : Projectile(Faction::None, ProjectileType::HELLFIRE) {}

  void draw() const override {
    DrawCircleV(stats.pos, (float)stats.size, BLACK);
  }
};
