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
      std::cerr << "Rocket Projectile texture missing\n";
      return;
    }

    AssetSystem::instance().drawTexture(tex, stats.pos.x, stats.pos.y,
                                        stats.size);
  }
};
