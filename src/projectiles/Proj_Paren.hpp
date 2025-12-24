#pragma once

#include "Projectile.hpp"
#include <cmath>

class Paren : public Projectile {
public:
  static Texture2D *projTexture;
  Paren() : Projectile(Faction::None, ProjectileType::PAREN, projTexture) {}

  void update(float dt, float bulletTime) override {
    if (bulletTime <= 2.0f)
      stats.size += std::sinf(bulletTime) * 0.8f;
    else
      stats.size -= std::sinf(bulletTime) * 0.8f;

    stats.pos.x += std::cosf(bulletTime) * stats.vel.x * dt;
    stats.pos.y += std::cosf(bulletTime) * stats.vel.y * dt;
    stats.lifetime -= dt;
  };

  void setTexture() override { texture = projTexture; }
};
