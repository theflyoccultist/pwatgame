#pragma once

#include "Projectile.hpp"

class Grenade : public Projectile {
public:
  Grenade() : Projectile(Faction::None, ProjectileType::GRENADE) {}

  void draw() const override {
    if (!isActive())
      return;

    Texture2D *tex = ProjectileTextures::get(ProjectileType::GRENADE);
    if (!tex) {
      std::cerr << "Grenade Projectile texture missing\n";
      return;
    }

    AssetSystem::instance().drawTexture(tex, stats.pos.x, stats.pos.y,
                                        stats.size);
  }
};
