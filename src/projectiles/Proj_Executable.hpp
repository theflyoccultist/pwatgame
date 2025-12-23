#pragma once

#include "Projectile.hpp"

class Executable : public Projectile {
public:
  static Texture2D *projTexture;
  Executable()
      : Projectile(Faction::None, ProjectileType::EXECUTABLE, projTexture) {}

  void setTexture() override { texture = projTexture; }
};
