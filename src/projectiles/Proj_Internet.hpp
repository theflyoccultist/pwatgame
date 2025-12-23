#pragma once

#include "Projectile.hpp"

class Internet : public Projectile {
public:
  static Texture2D *projTexture;
  Internet()
      : Projectile(Faction::None, ProjectileType::INTERNET, projTexture) {}

  void setTexture() override { texture = projTexture; }
};
