
#pragma once

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
      moveAccrossScreen(actorCooldown);
      p.type = ProjectileType::LAMBDA;
      p.spec = MiniBossDatabase::getWeaponSpec(p.type);
      shootTowardsPlayer(projMan, p);
    } else {
      resetPosition();
    }
  }

private:
  void moveAccrossScreen(float actorCooldown) {
    if (actorCooldown <= 1.0f) {
      stats.pos.x +=
          ((float)GetScreenHeight() - stats.size - stats.pos.x) * 0.25f;
      stats.pos.y +=
          ((float)GetScreenWidth() - stats.size - stats.pos.y) * 0.25f;
    }

    else if (actorCooldown <= 2.0f) {
      stats.pos.x += (0 - stats.pos.x) * 0.25f;
      stats.pos.y +=
          ((float)GetScreenWidth() - stats.size - stats.pos.y) * 0.25f;
    }

    else if (actorCooldown <= 3.0f) {
      stats.pos.x +=
          ((float)GetScreenHeight() - stats.size - stats.pos.x) * 0.25f;
      stats.pos.y += (0 - stats.pos.y) * 0.25f;
    }

    else if (actorCooldown <= 4.0f) {
      stats.pos.x += (0 - stats.pos.x) * 0.25f;
      stats.pos.y += (0 - stats.pos.y) * 0.25f;
    }
  }

  void resetPosition() {
    stats.pos.x += (stats.initialPos.x - stats.pos.x) * 0.25f;
    stats.pos.y += (stats.initialPos.y - stats.pos.y) * 0.25f;
  }
};
