#pragma once

#include "Projectile.hpp"

class Grenade : public Projectile {
public:
  static Texture2D *projTexture;
  Grenade() : Projectile(Faction::None, ProjectileType::GRENADE, projTexture) {}

  void setTexture() override { texture = projTexture; }
};
