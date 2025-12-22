#pragma once

#include "Projectile.hpp"
#include <cmath>
#include <iostream>

class Recon : public Projectile {
public:
  Recon() : Projectile(Faction::None, ProjectileType::RECON) {}

  void update(float dt) override {
    bulletTime += dt;
    float accel = std::expf(bulletTime * 0.6f);
    stats.vel.x += stats.vel.x * accel * dt;
    stats.vel.y += stats.vel.y * accel * dt;

    stats.pos.x += stats.vel.x * dt;
    stats.pos.y += stats.vel.y * dt;

    stats.lifetime -= dt;

    if (bulletTime >= 2.0f)
      bulletTime = 0.0f;
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
  float bulletTime = 0.0f;
};
