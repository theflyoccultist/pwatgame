#pragma once

#include "Projectile.hpp"
#include <cmath>
#include <iostream>

class Lambda : public Projectile {
public:
  Lambda() : Projectile(Faction::None, ProjectileType::LAMBDA) {}

  void update(float dt, float bulletTime) override {
    float speed =
        std::sqrtf(stats.vel.x * stats.vel.x + stats.vel.y * stats.vel.y);

    float growth = 1.0f + bulletTime * bulletTime;

    stats.vel.x = (stats.vel.x / speed) * growth;
    stats.vel.y = (stats.vel.y / speed) * growth;

    stats.pos.x += stats.vel.x * dt;
    stats.pos.y += stats.vel.y * dt;

    stats.lifetime -= dt;
  }

  void draw() const override {
    if (!isActive())
      return;

    Texture2D *tex = ProjectileTextures::get(ProjectileType::LAMBDA);
    if (!tex) {
      std::cerr << "Lambda Projectile texture missing\n";
      return;
    }

    AssetSystem::instance().drawTexture(tex, stats.pos.x, stats.pos.y,
                                        stats.size);
  }
};
