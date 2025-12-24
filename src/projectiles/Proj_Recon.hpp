#pragma once

#include "Projectile.hpp"
#include <cmath>

class Recon : public Projectile {
public:
  static Texture2D *projTexture;
  Recon() : Projectile(Faction::None, ProjectileType::RECON, projTexture) {}

  void update(float dt, float bulletTime) override {
    float accel = 1.0f * bulletTime;

    stats.vel.x += stats.vel.x * accel * dt;
    stats.vel.y += stats.vel.y * accel * dt;

    stats.pos.x += stats.vel.x * dt;
    stats.pos.y += stats.vel.y * dt;

    stats.lifetime -= dt;
  }

  void setTexture() override { texture = projTexture; }
};
