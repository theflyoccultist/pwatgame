#pragma once

#include "Enemy.hpp"
#include <array>
#include <raylib.h>

class Godsip : public Enemy {
public:
  Godsip(Vector2 pos, std::array<Texture2D *, 3> textures)
      : Enemy(EnemyType::GODSIP, pos, Random::rangeFloat(50, 51),
              Random::rangeInt(50, 70), 80, textures) {}

  void update(float delta, Vector2 playerPos) override {
    dashTimer += delta;

    if (!isDashing) {
      if (dashTimer >= dashCooldown) {
        Vector2 rawDir = {playerPos.x - position.x, playerPos.y - position.y};
        float length = std::sqrt(rawDir.x * rawDir.x + rawDir.y * rawDir.y);

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
      position.x += dashDir.x * speed * delta * 12;
      position.y += dashDir.y * speed * delta * 12;
      ClampEntities::clamp(position, 80);

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
