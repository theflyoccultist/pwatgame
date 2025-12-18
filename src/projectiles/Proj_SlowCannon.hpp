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
      std::cerr << "SlowCannon Projectile texture missing\n";
      return;
    }

    AssetSystem::instance().drawTexture(tex, stats.pos.x, stats.pos.y,
                                        stats.size);
  }
};
