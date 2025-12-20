#pragma once

#include "Projectile.hpp"

class Update : public Projectile {
public:
  Update() : Projectile(Faction::None, ProjectileType::UPDATE) {}

  void draw() const override {
    if (!isActive())
      return;

    Texture2D *tex = ProjectileTextures::get(ProjectileType::UPDATE);
    if (!tex) {
      std::cerr << "Internet Explorer Projectile texture missing\n";
      return;
    }

    AssetSystem::instance().drawTexture(tex, stats.pos.x, stats.pos.y,
                                        stats.size);
  }
};
