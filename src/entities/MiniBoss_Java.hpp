#pragma once

#include "MiniBoss.hpp"
#include "MiniBossDatabase.hpp"

class Java : public MiniBoss {
public:
  static std::array<Texture2D *, 3> sharedTextures;
  Java() : MiniBoss(MiniBossType::JAVA, sharedTextures) {}

  void setTexture() override { textures = sharedTextures; }

  void update([[maybe_unused]] ShootParams &p,
              [[maybe_unused]] ProjectileManager &projMan,
              float actorCooldown) override {
    if (actorCooldown <= 5.0f) {
      p.type = ProjectileType::INTERNET;
      p.spec = MiniBossDatabase::getWeaponSpec(p.type);
      shootJIT(projMan, p, shootAccel);
    } else if (actorCooldown > 5.0f && actorCooldown <= 5.5f) {
      p.type = ProjectileType::EXECUTABLE;
      p.spec = MiniBossDatabase::getWeaponSpec(p.type);
      shootGarbageBurst(projMan, p);
    } else if (actorCooldown > 5.5f && actorCooldown <= 12.0f) {
      p.type = ProjectileType::GRENADE;
      p.spec = MiniBossDatabase::getWeaponSpec(p.type);
      shootTowardsPlayer(projMan, p);
    } else {
      shootAccel = 0.0f;
    }
  }

private:
  float shootAccel = 0.0f;
};
