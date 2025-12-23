#pragma once

#include "Projectile.hpp"
#include <raylib.h>

class LongRange : public Projectile {
public:
  static Texture2D *projTexture;
  LongRange()
      : Projectile(Faction::None, ProjectileType::LONGRANGE, projTexture) {}

  void setTexture() override { texture = projTexture; }
};
