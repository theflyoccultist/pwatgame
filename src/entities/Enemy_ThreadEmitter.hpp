#pragma once

#include "Enemy.hpp"
#include "EnemyDatabase.hpp"
#include <array>
#include <cmath>
#include <raylib.h>

struct orbitState {
  float orbitAngle = Random::rangeFloat(0.0f, 2.0f * PI);
  float orbitSpeed = Random::rangeFloat(0.5f, 2.0f);
  float orbitRadius = Random::rangeFloat(80.0f, 160.0f);
  Vector2 center = {250, 250};
};

class ThreadEmitter : public Enemy {
public:
  static std::array<Texture2D *, 3> sharedTextures;
  ThreadEmitter() : Enemy(EnemyType::THREADEMITTER, sharedTextures) {}

  void setTexture() override { textures = sharedTextures; }

  void update(ShootParams &p, ProjectileManager &projMan,
              float actorCooldown) override {

    os.orbitAngle += os.orbitSpeed * p.dt;

    stats.pos.x = os.center.x + std::cosf(os.orbitAngle) * os.orbitRadius;
    stats.pos.y = os.center.y + std::sinf(os.orbitAngle) * os.orbitRadius;

    if (actorCooldown < 7.8f) {
      if (inFireWindow(actorCooldown, 0.6f, 0.35f)) {
        p.type = ProjectileType::INTERNET;
        p.spec = EnemyDatabase::getWeaponSpec(p.type);
        shootThreadJIT(projMan, p, actorCooldown);
      }
    } else {
      killEntity();
    }
  }

private:
  void resetPosition() { stats.pos = stats.initialPos; }
  orbitState os;

  bool inFireWindow(float t, float period, float duty) {
    float phase = std::fmodf(t, period);
    return phase < (period * duty);
  }
};
