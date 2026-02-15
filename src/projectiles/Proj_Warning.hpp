#pragma once

#include "Projectile.hpp"
#include <raylib.h>

class Warning : public Projectile {
public:
  static Texture2D *projTexture;
  Warning() : Projectile(Faction::None, ProjectileType::WARNING, projTexture) {}

  void setTexture() override { texture = projTexture; }
};
