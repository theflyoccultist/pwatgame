#pragma once

#include "Projectile.hpp"

class Hellfire : public Projectile {
public:
  Hellfire() : Projectile(Faction::None, ProjectileType::HELLFIRE) {}

  void draw() const override {
    if (!isActive())
      return;

    Texture2D *tex = ProjectileTextures::get(ProjectileType::HELLFIRE);
    if (!tex) {
      std::cerr << "Grenade Projectile texture missing\n";
      return;
    }

    AssetSystem::instance().drawTexture(tex, (int)stats.pos.x,
                                        (int)stats.pos.y);
  }
};
