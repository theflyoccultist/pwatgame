#pragma once

#include <cmath>
#include <projectiles/Projectile.hpp>

class Update : public Projectile {
public:
  static Texture2D *projTexture;
  Update() : Projectile(Faction::None, ProjectileType::UPDATE, projTexture) {}

  void update(float dt, float bulletTimer) override {
    stats.pos.x += baseVel.x * dt;
    stats.pos.y +=
        baseVel.y * dt + std::sin(bulletTimer * frequency) * amplitude * dt;

    stats.lifetime -= dt;
  }

  void setTexture() override { texture = projTexture; }

private:
  float amplitude = 20.0f;
  float frequency = 6.0f;
  Vector2 baseVel;
};
