#pragma once

#include "../utils/Random.hpp"
#include "Enemy.hpp"
#include "EnemyDatabase.hpp"
#include <array>
#include <raylib.h>

class Zomb : public Enemy {
public:
  static std::array<Texture2D *, 3> sharedTextures;
  Zomb() : Enemy(EnemyType::ZOMB, sharedTextures) {}

  void setTexture() override { textures = sharedTextures; }

  void update(ShootParams &p, ProjectileManager &projMan,
              float actorCooldown) override {
    p.type = ProjectileType::SLOWCANNON;
    p.spec = EnemyDatabase::getWeaponSpec(p.type);

    if (isX) {
      stats.pos.x += stats.speed * p.dt * dirX;
      if (stats.pos.x >= 730.f)
        dirX = -1;
      else if (stats.pos.x <= 0)
        dirX = 1;
    } else {
      stats.pos.y += stats.speed * p.dt * dirY;
      if (stats.pos.y >= 730.f)
        dirY = -1;
      else if (stats.pos.y <= 0)
        dirY = 1;
    }

    if ((actorCooldown >= 2.0f && actorCooldown <= 4.0f) ||
        actorCooldown >= 5.0f)
      shootInVoid(projMan, p);
  }

private:
  float dirX = 1;
  float dirY = 1;
  const bool isX = Random::chance(.5f);
};
