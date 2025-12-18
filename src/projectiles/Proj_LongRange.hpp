#pragma once

#include "Projectile.hpp"
#include <raylib.h>

class LongRange : public Projectile {
public:
  LongRange() : Projectile(Faction::None, ProjectileType::LONGRANGE) {}

  void draw() const override {
    if (!isActive())
      return;

    Texture2D *tex = ProjectileTextures::get(ProjectileType::LONGRANGE);
    if (!tex) {
      std::cerr << "Longrange Projectile texture missing\n";
      return;
    }

    AssetSystem::instance().drawTexture(tex, stats.pos.x, stats.pos.y,
                                        stats.size);
  }
};
