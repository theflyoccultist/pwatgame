#pragma once

#include "MiniBoss.hpp"
#include "MiniBossDatabase.hpp"
#include <array>
#include <cmath>
#include <raylib.h>

class Windows : public MiniBoss {
public:
  static std::array<Texture2D *, 3> sharedTextures;
  Windows() : MiniBoss(MiniBossType::WINDOWS, sharedTextures) {}

  void setTexture() override { textures = sharedTextures; }

  void update(ShootParams &p, ProjectileManager &projMan,
              float bossCooldown) override {
    stats.pos = {stats.pos.x, stats.pos.y + (sinf(bossCooldown) * .25f)};

    if (bossCooldown <= 2.0f) {
      moveTowardsPlayer(p.dt, p.playerPos);
      p.type = ProjectileType::UPDATE;
      p.spec = MiniBossDatabase::getWeaponSpec(ProjectileType::UPDATE);
      shootRadialBurst(projMan, p, 3);

    } else if (bossCooldown <= 3.0f) {
      if (stats.currentHP <= stats.totalHP)
        stats.currentHP++;

    } else if (bossCooldown <= 4.0f) {
      p.type = ProjectileType::INTERNET;
      p.spec = MiniBossDatabase::getWeaponSpec(ProjectileType::INTERNET);
      shootTowardsPlayer(projMan, p);

    } else if (bossCooldown <= 6.0f) {
      p.type = ProjectileType::EXECUTABLE;
      p.spec = MiniBossDatabase::getWeaponSpec(ProjectileType::EXECUTABLE);
      shootRadialBurst(projMan, p, 8);

    } else if (bossCooldown <= 8.0f) {
      p.type = ProjectileType::UPDATE;
      p.spec = MiniBossDatabase::getWeaponSpec(ProjectileType::UPDATE);
      shootRadialBurst(projMan, p, 3);
    }
  }

private:
  void moveTowardsPlayer(float dt, Vector2 playerPos) {
    Vector2 dir = {playerPos.x - stats.pos.x, playerPos.y - stats.pos.y};

    float length = std::sqrtf(dir.x * dir.x + dir.y * dir.y);
    if (length > 0.0f) {
      dir.x /= length;
      dir.y /= length;
    }

    stats.pos.x += dir.x * stats.speed * dt;
    stats.pos.y += dir.y * stats.speed * dt;
  }
};
