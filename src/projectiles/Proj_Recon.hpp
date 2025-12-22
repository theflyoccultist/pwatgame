#pragma once

#include "Projectile.hpp"
#include <cmath>

class Recon : public Projectile {
public:
  Recon() : Projectile(Faction::None, ProjectileType::RECON) {}

  void update(float dt) override {
    time += dt;

    float cosh = std::powf(std::cosh(time), 2);
    stats.pos.x += stats.vel.x * dt + cosh;
    stats.pos.y += stats.vel.y * dt + cosh;

    stats.lifetime -= dt;

    if (stats.lifetime <= 0.0f)
      time = 0.0f;
  }

  void draw() const override {
    if (!isActive())
      return;

    Texture2D *tex = ProjectileTextures::get(ProjectileType::RECON);
    if (!tex) {
      std::cerr << "Recon Projectile texture missing\n";
      return;
    }

    AssetSystem::instance().drawTexture(tex, stats.pos.x, stats.pos.y,
                                        stats.size);
  }

private:
  float time = 0.0f;
};
