#pragma once

#include "Enemy.hpp"
#include "EnemyDatabase.hpp"
#include <array>
#include <raylib.h>

class Swarmer : public Enemy {
public:
  static std::array<Texture2D *, 3> sharedTextures;
  Swarmer() : Enemy(EnemyType::SWARMER, sharedTextures) {}

  void setTexture() override { textures = sharedTextures; }

  void update(ShootParams &p, ProjectileManager &projMan,
              float actorCooldown) override {
    Vector2 dir = {p.playerPos.x - stats.pos.x, p.playerPos.y - stats.pos.y};
    float length = std::sqrtf(dir.x * dir.x + dir.y * dir.y);

    if (actorCooldown <= 2.0f)
      moveTowards(p, dir, length);

    else if (length < 500.0f) {
      p.type = ProjectileType::LONGRANGE;
      p.spec = EnemyDatabase::getWeaponSpec(p.type);
      shootTowardsPlayer(projMan, p);
    }
  };

private:
  void moveTowards(ShootParams &p, Vector2 dir, float length) {
    if (length > 0.0f) {
      dir.x /= length;
      dir.y /= length;
    }

    stats.pos.x += dir.x * stats.speed * p.dt;
    stats.pos.y += dir.y * stats.speed * p.dt;
  }
};
