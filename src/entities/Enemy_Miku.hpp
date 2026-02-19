#pragma once

#include <entities/Enemy.hpp>
#include <entities/EnemyDatabase.hpp>

class Miku : public Enemy {
public:
  static std::array<Texture2D *, 3> sharedTextures;
  Miku() : Enemy(EnemyType::MIKU, sharedTextures) {}

  void setTexture() override { textures = sharedTextures; }

  void update(ShootParams &p, ProjectileManager &projMan,
              float actorCooldown) override {
    if (actorCooldown <= 2.0f) {
      p.type = ProjectileType::ELIXIR;
      p.spec = EnemyDatabase::getWeaponSpec(p.type);
      shootDiagonally(projMan, p);
    }

    if (actorCooldown >= 2.0f) {
      stats.pos.x += stats.speed * p.dt * (float)dirX;
      if (stats.pos.x >= 730.f)
        dirX = -1;
      else if (stats.pos.x <= 0)
        dirX = 1;
      stats.pos.y -= std::sin(actorCooldown) * stats.speed * p.dt;
    }
  }

private:
  int dirX = 1;
};
