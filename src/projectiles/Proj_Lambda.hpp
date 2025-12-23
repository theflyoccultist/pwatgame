#pragma once

#include "Projectile.hpp"
#include <cmath>

class Lambda : public Projectile {
public:
  static Texture2D *projTexture;
  Lambda() : Projectile(Faction::None, ProjectileType::LAMBDA, projTexture) {}

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

  void setTexture() override { texture = projTexture; }
};
