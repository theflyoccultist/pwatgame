#pragma once

#include <cmath>
#include <projectiles/Projectile.hpp>

class Elixir : public Projectile {
public:
  static Texture2D *projTexture;
  Elixir() : Projectile(Faction::None, ProjectileType::ELIXIR, projTexture) {}

  void update(float dt, float bulletTime) override {
    float accel = (float)std::fmod(bulletTime, 3);

    stats.vel.x += stats.vel.x * accel * dt;
    stats.vel.y += stats.vel.y * accel * dt;

    stats.pos.x += stats.vel.x * dt;
    stats.pos.y += stats.vel.y * dt;

    stats.lifetime -= dt;
  }

  void setTexture() override { texture = projTexture; }
};
