
#pragma once

#include "../utils/clampEntities.hpp"
#include "MiniBoss.hpp"
#include "MiniBossDatabase.hpp"
#include <array>
#include <cmath>
#include <raylib.h>

class Lisp : public MiniBoss {
public:
  static std::array<Texture2D *, 3> sharedTextures;
  Lisp() : MiniBoss(MiniBossType::LISP, sharedTextures) {}

  void setTexture() override { textures = sharedTextures; }

  void update(ShootParams &p, ProjectileManager &projMan,
              float actorCooldown) override {

    if (actorCooldown <= 4.0f) {
      p.type = ProjectileType::LAMBDA;
      p.spec = MiniBossDatabase::getWeaponSpec(p.type);
      shootTowardsPlayer(projMan, p);
      copyPlayerMovements(actorCooldown);
    } else {
      resetPosition();
    }
  }

private:
  void copyPlayerMovements(float actorCooldown) {

    if (actorCooldown <= 1.0f)
      stats.pos = {(float)GetScreenHeight() - stats.size,
                   (float)GetScreenWidth() - stats.size};

    else if (actorCooldown <= 2.0f)
      stats.pos = {0, (float)GetScreenWidth() - stats.size};

    else if (actorCooldown <= 3.0f)
      stats.pos = {(float)GetScreenHeight() - stats.size, 0};

    else if (actorCooldown <= 4.0f)
      stats.pos = {0, 0};

    ClampEntities::clamp(stats.pos, (int)stats.size);
  }

  void resetPosition() { stats.pos = stats.initialPos; }
};
