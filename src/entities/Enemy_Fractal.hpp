#pragma once

#include <entities/Enemy.hpp>
#include <entities/EnemyDatabase.hpp>

class Fractal : public Enemy {
public:
  static std::array<Texture2D *, 3> sharedTextures;
  Fractal() : Enemy(EnemyType::FRACTAL, sharedTextures) {}

  void setTexture() override { textures = sharedTextures; }

  void update(ShootParams &p, ProjectileManager &projMan,
              float actorCooldown) override {
    p.type = ProjectileType::RECON;
    p.spec = EnemyDatabase::getWeaponSpec(p.type);

    stats.pos.y += stats.speed * p.dt * dirY;
    if (stats.pos.y >= 730.f)
      dirY = -1;
    else if (stats.pos.y <= 0)
      dirY = 1;

    if (actorCooldown <= 6.0f)
      shootFractals(projMan, p, actorCooldown);
  }

private:
  float dirY = 1;
};
