#pragma once

#include "Enemy.hpp"
#include "EnemyDatabase.hpp"
#include <array>
#include <cmath>
#include <raylib.h>

class Duo : public Enemy {
public:
  static std::array<Texture2D *, 3> sharedTextures;
  Duo() : Enemy(EnemyType::DUO, sharedTextures) {}

  void setTexture() override { textures = sharedTextures; }

  void update(ShootParams &p, ProjectileManager &projMan,
              float actorCooldown) override {

    if (actorCooldown <= 1.5f) {
      p.type = ProjectileType::INTERNET;
      p.spec = EnemyDatabase::getWeaponSpec(p.type);
      shootTowardsPlayer(projMan, p);

    } else if (actorCooldown >= 3.5f) {
      p.type = ProjectileType::EXECUTABLE;
      p.spec = EnemyDatabase::getWeaponSpec(p.type);
      shootGarbageBurst(projMan, p);
    }
  }
};
