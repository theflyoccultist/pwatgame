#pragma once

#include "Projectile.hpp"
#include <raylib.h>

class Uzi : public Projectile {
public:
  Uzi() : Projectile(Faction::None, ProjectileType::UZI) {}

  void draw() const override {
    if (!isActive())
      return;

    Texture2D *tex = ProjectileTextures::get(ProjectileType::UZI);
    if (!tex) {
      std::cerr << "Grenade Projectile texture missing\n";
      return;
    }

    AssetSystem::instance().drawTexture(tex, (int)stats.pos.x,
                                        (int)stats.pos.y);
  }
};
