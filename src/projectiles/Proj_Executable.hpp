#pragma once

#include "Projectile.hpp"

class Executable : public Projectile {
public:
  Executable() : Projectile(Faction::None, ProjectileType::EXECUTABLE) {}

  void draw() const override {
    if (!isActive())
      return;

    Texture2D *tex = ProjectileTextures::get(ProjectileType::EXECUTABLE);
    if (!tex) {
      std::cerr << ".exe Projectile texture missing\n";
      return;
    }

    AssetSystem::instance().drawTexture(tex, stats.pos.x, stats.pos.y,
                                        stats.size);
  }
};
