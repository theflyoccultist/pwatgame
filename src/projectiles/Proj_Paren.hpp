#pragma once

#include <cmath>
#include <projectiles/Projectile.hpp>

class Paren : public Projectile {
public:
  static Texture2D *projTexture;
  Paren() : Projectile(Faction::None, ProjectileType::PAREN, projTexture) {}

  void update(float dt, float bulletTime) override {
    if (bulletTime <= 2.0f)
      stats.size += std::sin(bulletTime) * 0.8f;
    else
      stats.size -= std::sin(bulletTime) * 0.8f;

    stats.pos.x += std::cos(bulletTime) * stats.vel.x * dt;
    stats.pos.y += std::cos(bulletTime) * stats.vel.y * dt;
    stats.lifetime -= dt;
  };

  void setTexture() override { texture = projTexture; }
};
