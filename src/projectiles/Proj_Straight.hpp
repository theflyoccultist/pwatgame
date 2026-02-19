#pragma once

#include <projectiles/Projectile.hpp>
#include <raylib.h>

class Straight : public Projectile {
public:
  static Texture2D *projTexture;
  Straight()
      : Projectile(Faction::None, ProjectileType::STRAIGHT, projTexture) {}

  void setTexture() override { texture = projTexture; }
};
