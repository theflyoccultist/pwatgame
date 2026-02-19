#pragma once

#include <projectiles/Projectile.hpp>
#include <raylib.h>

class SlowCannon : public Projectile {
public:
  static Texture2D *projTexture;
  SlowCannon()
      : Projectile(Faction::None, ProjectileType::SLOWCANNON, projTexture) {}

  void setTexture() override { texture = projTexture; }
};
