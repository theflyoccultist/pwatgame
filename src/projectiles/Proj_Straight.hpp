#pragma once

#include "Projectile.hpp"
#include <raylib.h>

class Straight : public Projectile {
public:
  Straight() : Projectile(Faction::None, ProjectileType::STRAIGHT) {}

  void draw() const override {
    if (!isActive())
      return;

    Texture2D *tex = ProjectileTextures::get(ProjectileType::STRAIGHT);
    if (!tex) {
      std::cerr << "Grenade Projectile texture missing\n";
      return;
    }

    AssetSystem::instance().drawTexture(tex, (int)stats.pos.x,
                                        (int)stats.pos.y);
  }
};
