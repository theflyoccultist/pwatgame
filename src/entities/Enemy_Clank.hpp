#pragma once

#include "Enemy.hpp"
#include "EnemyDatabase.hpp"
#include <array>
#include <iostream>
#include <raylib.h>

class Clank : public Enemy {
public:
  static std::array<Texture2D *, 3> sharedTextures;
  Clank() : Enemy(EnemyType::CLANK, sharedTextures) {}

  void setTexture() override { textures = sharedTextures; }

  void update(ShootParams &p, ProjectileManager &projMan,
              float actorCooldown) override {

    p.type = ProjectileType::SLOWCANNON;
    p.spec = EnemyDatabase::getWeaponSpec(p.type);
    shootInVoid(projMan, p);
    std::cout << stats.speed << "\n";

    moveInSquare(p, actorCooldown);
  }

private:
  float dirX = 1;
  float dirY = 1;
  const float spdMult = Random::rangeFloat(0.7f, 4.5f);

  void moveInSquare(ShootParams &p, float actorCooldown) {
    if (actorCooldown <= 2.0f) {
      // move right
      stats.speed += spdMult;
      dirX = 1;
      stats.pos.x += stats.speed * p.dt * dirX;
    }

    else if (actorCooldown <= 4.0f) {
      // move up
      stats.speed -= spdMult;
      dirY = -1;
      stats.pos.y += stats.speed * p.dt * dirY;

    } else if (actorCooldown <= 6.0f) {
      // move left
      stats.speed += spdMult;
      dirX = -1;
      stats.pos.x += stats.speed * p.dt * dirX;

    } else if (actorCooldown <= 8.0f) {
      // move down
      stats.speed -= spdMult;
      dirY = 1;
      stats.pos.y += stats.speed * p.dt * dirY;
    }
  }
};
