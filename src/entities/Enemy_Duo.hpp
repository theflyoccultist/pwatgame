#pragma once

#include <entities/Enemy.hpp>
#include <entities/EnemyDatabase.hpp>

class Duo : public Enemy {
public:
  static std::array<Texture2D *, 3> sharedTextures;
  Duo() : Enemy(EnemyType::DUO, sharedTextures) {}

  void setTexture() override { textures = sharedTextures; }

  void update(ShootParams &p, ProjectileManager &projMan,
              float actorCooldown) override {
    float duoCooldown = std::fmod(actorCooldown, 4.0f);

    if (duoCooldown <= 1.5f) {
      p.type = ProjectileType::INTERNET;
      p.spec = EnemyDatabase::getWeaponSpec(p.type);
      shootTowardsPlayer(projMan, p);

    } else if (duoCooldown >= 3.5f && duoCooldown <= 4.0f) {
      p.type = ProjectileType::EXECUTABLE;
      p.spec = EnemyDatabase::getWeaponSpec(p.type);
      shootGarbageBurst(projMan, p);
    }
  }
};
