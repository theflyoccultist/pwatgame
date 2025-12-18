#pragma once

#include "Projectile.hpp"
#include <raylib.h>

class SlowCannon : public Projectile {
public:
  SlowCannon() : Projectile(Faction::None, ProjectileType::SLOWCANNON) {}

  void draw() const override {
    if (!isActive())
      return;

    Texture2D *tex = ProjectileTextures::get(ProjectileType::SLOWCANNON);
    if (!tex) {
      std::cerr << "Grenade Projectile texture missing\n";
      return;
    }

    AssetSystem::instance().drawTexture(tex, (int)stats.pos.x,
                                        (int)stats.pos.y);
  }
};
