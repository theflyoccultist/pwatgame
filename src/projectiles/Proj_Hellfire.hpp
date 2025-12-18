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
      std::cerr << "Hellfire Projectile texture missing\n";
      return;
    }

    AssetSystem::instance().drawTexture(tex, stats.pos.x, stats.pos.y,
                                        stats.size);
  }
};
