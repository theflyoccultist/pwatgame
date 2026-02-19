#pragma once

#include <projectiles/Projectile.hpp>
#include <raylib.h>

class Uzi : public Projectile {
public:
  static Texture2D *projTexture;
  Uzi() : Projectile(Faction::None, ProjectileType::UZI, projTexture) {}

  void setTexture() override { texture = projTexture; }
};
