#pragma once

#include "MiniBoss.hpp"
#include "MiniBossDatabase.hpp"

class Rust : public MiniBoss {
public:
  static std::array<Texture2D *, 3> sharedTextures;
  Rust() : MiniBoss(MiniBossType::RUST, sharedTextures) {}

  void setTexture() override { textures = sharedTextures; }

  void update(ShootParams &p, ProjectileManager &projMan,
              float actorCooldown) override {
    if (actorCooldown <= 4.0f) {
      p.type = ProjectileType::LONGRANGE;
      p.spec = MiniBossDatabase::getWeaponSpec(p.type);
      shootTowardsPlayer(projMan, p);
    }
  }
};
