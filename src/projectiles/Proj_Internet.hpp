#pragma once

#include "Projectile.hpp"

class Internet : public Projectile {
public:
  Internet() : Projectile(Faction::None, ProjectileType::INTERNET) {}

  void draw() const override {
    if (!isActive())
      return;

    Texture2D *tex = ProjectileTextures::get(ProjectileType::INTERNET);
    if (!tex) {
      std::cerr << "Internet Explorer Projectile texture missing\n";
      return;
    }

    AssetSystem::instance().drawTexture(tex, stats.pos.x, stats.pos.y,
                                        stats.size);
  }
};
