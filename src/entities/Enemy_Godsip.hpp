#pragma once

#include "../utils/Random.hpp"
#include "Enemy.hpp"
#include <array>
#include <raylib.h>

class Godsip : public Enemy {
public:
  static std::array<Texture2D *, 3> sharedTextures;
  Godsip() : Enemy(EnemyType::GODSIP, sharedTextures) {}

  void reset(Vector2 pos) {
    stats.active = true;
    stats.pos = pos;
    stats.speed = Random::rangeFloat(50, 51);
    stats.totalHP = Random::rangeInt(50, 70);
    stats.currentHP = stats.totalHP;

    textures = sharedTextures;
  }

  void update(float delta, Vector2 playerPos) override {
    dashTimer += delta;

    if (!isDashing) {
      if (dashTimer >= dashCooldown) {
        Vector2 rawDir = {playerPos.x - stats.pos.x, playerPos.y - stats.pos.y};
        float length = std::sqrtf(rawDir.x * rawDir.x + rawDir.y * rawDir.y);

        if (length > 0.0f) {
          dashDir.x = rawDir.x / length;
          dashDir.y = rawDir.y / length;
        } else {
          dashDir = {0, 0};
        }

        isDashing = true;
        dashTimer = 0.f;
      }
    }

    if (isDashing) {
      stats.pos.x += dashDir.x * stats.speed * delta * 12;
      stats.pos.y += dashDir.y * stats.speed * delta * 12;
      ClampEntities::clamp(stats.pos, 80);

      if (dashTimer >= dashDuration) {
        isDashing = false;
        dashTimer = 0.f;
      }
    }
  };

private:
  float dashTimer = 0.f;
  float dashCooldown = 2.f;
  float dashDuration = 1.5f;
  Vector2 dashDir{};
  bool isDashing = false;
};
