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

    if (actorCooldown > 0.5f && actorCooldown < 1.5f) {
      p.type = ProjectileType::WARNING;
      p.spec = MiniBossDatabase::getWeaponSpec(p.type);
      lockedTarget(projMan, p);
    }

    if (actorCooldown >= 1.5f && actorCooldown <= 2.5f) {
      p.type = ProjectileType::EXECUTABLE;
      p.spec = MiniBossDatabase::getWeaponSpec(p.type);
      lockedTarget(projMan, p);
    }

    if (actorCooldown >= 3.5f && actorCooldown <= 4.5f) {
      p.type = ProjectileType::EXECUTABLE;
      p.spec = MiniBossDatabase::getWeaponSpec(p.type);
      shootSpiral(projMan, p);
    }

    if (actorCooldown > 4.5f && actorCooldown <= 5.0f) {
      stats.pos.x +=
          ((float)GetScreenHeight() - stats.size - stats.pos.x) * 0.25f;
    }

    if (actorCooldown > 5.0f && actorCooldown <= 5.5f) {
      stats.pos.x += (0 - stats.pos.x) * 0.25f;
    }

    if (actorCooldown > 5.5f && actorCooldown <= 6.5f) {
      resetPosition();
      shootTowardsPlayer(projMan, p);
    }

    if (actorCooldown > 6.5f && actorCooldown <= 7.0f) {
      stats.pos.x += (0 - stats.pos.x) * 0.25f;
    }

    if (actorCooldown > 7.0f && actorCooldown <= 7.5f) {
      stats.pos.x +=
          ((float)GetScreenHeight() - stats.size - stats.pos.x) * 0.25f;
    }

    if (actorCooldown > 7.5f && actorCooldown < 8.0f) {
      resetPosition();
    }

    if (actorCooldown >= 8.0f && actorCooldown <= 8.5f)
      lockOn(p);

    if (actorCooldown > 8.5f && actorCooldown < 9.5f) {
      p.type = ProjectileType::WARNING;
      p.spec = MiniBossDatabase::getWeaponSpec(p.type);
      lockedTarget(projMan, p);
    }

    if (actorCooldown >= 9.5f && actorCooldown <= 10.5f) {
      p.type = ProjectileType::EXECUTABLE;
      p.spec = MiniBossDatabase::getWeaponSpec(p.type);
      lockedTarget(projMan, p);
    }

    if (actorCooldown >= 11.5f && actorCooldown <= 13.0f) {
      p.type = ProjectileType::EXECUTABLE;
      p.spec = MiniBossDatabase::getWeaponSpec(p.type);
      shootSpiral(projMan, p);
    }

    // TODO: add some movement patterns.
  }

private:
  void resetPosition() {
    stats.pos.x += (stats.initialPos.x - stats.pos.x) * 0.25f;
    stats.pos.y += (stats.initialPos.y - stats.pos.y) * 0.25f;
  }
};
