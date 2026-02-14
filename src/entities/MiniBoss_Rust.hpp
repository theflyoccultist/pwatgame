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
    if (actorCooldown <= 0.5f)
      lockOn(p);

    // TODO: Add warning step.

    if (actorCooldown >= 1.5f && actorCooldown <= 2.5f) {
      p.type = ProjectileType::EXECUTABLE;
      p.spec = MiniBossDatabase::getWeaponSpec(p.type);
      lockedTarget(projMan, p);
    }

    if (actorCooldown >= 2.5f && actorCooldown <= 4.0f) {
      p.type = ProjectileType::EXECUTABLE;
      p.spec = MiniBossDatabase::getWeaponSpec(p.type);
      shootSpiral(projMan, p);
    }

    // TODO: add some movement patterns.

    if (actorCooldown >= 8.0f && actorCooldown <= 8.5f)
      lockOn(p);

    // TODO: Add warning step.

    if (actorCooldown >= 9.5f && actorCooldown <= 10.5f) {
      p.type = ProjectileType::EXECUTABLE;
      p.spec = MiniBossDatabase::getWeaponSpec(p.type);
      lockedTarget(projMan, p);
    }

    if (actorCooldown >= 10.5f && actorCooldown <= 12.0f) {
      p.type = ProjectileType::EXECUTABLE;
      p.spec = MiniBossDatabase::getWeaponSpec(p.type);
      shootSpiral(projMan, p);
    }

    // TODO: add some movement patterns.
  }
};
