#pragma once

#include "Projectile.hpp"
#include <raylib.h>

class Rocket : public Projectile {
public:
  Rocket() : Projectile(Faction::None, ProjectileType::ROCKET) {}

  void draw() const override {
    if (!isActive())
      return;

    Texture2D *tex = ProjectileTextures::get(ProjectileType::ROCKET);
    if (!tex) {
      std::cerr << "Grenade Projectile texture missing\n";
      return;
    }

    AssetSystem::instance().drawTexture(tex, (int)stats.pos.x,
                                        (int)stats.pos.y);
  }
};
