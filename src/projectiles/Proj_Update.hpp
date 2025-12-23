#pragma once

#include "Projectile.hpp"
#include <cmath>

class Update : public Projectile {
public:
  Update() : Projectile(Faction::None, ProjectileType::UPDATE) {}

  void update(float dt, [[maybe_unused]] float bulletTimer) override {
    time += dt;

    stats.pos.x += baseVel.x * dt;
    stats.pos.y +=
        baseVel.y * dt + std::sinf(time * frequency) * amplitude * dt;

    stats.lifetime -= dt;
  }

  void draw() const override {
    if (!isActive())
      return;

    Texture2D *tex = ProjectileTextures::get(ProjectileType::UPDATE);
    if (!tex) {
      std::cerr << "Windows Update Projectile texture missing\n";
      return;
    }

    AssetSystem::instance().drawTexture(tex, stats.pos.x, stats.pos.y,
                                        stats.size);
  }

private:
  float time = 0.0f;
  float amplitude = 20.0f;
  float frequency = 6.0f;
  Vector2 baseVel;
};
