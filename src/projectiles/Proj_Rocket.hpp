#pragma once

#include "Projectile.hpp"
#include <raylib.h>

class Rocket : public Projectile {
public:
  static Texture2D *projTexture;
  Rocket() : Projectile(Faction::None, ProjectileType::ROCKET, projTexture) {}

  void setTexture() override { texture = projTexture; }
};
