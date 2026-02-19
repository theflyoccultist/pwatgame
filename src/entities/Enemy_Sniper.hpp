#pragma once

#include <entities/Enemy.hpp>
#include <entities/EnemyDatabase.hpp>
#include <utils/clampEntities.hpp>

class Sniper : public Enemy {
public:
  static std::array<Texture2D *, 3> sharedTextures;
  Sniper() : Enemy(EnemyType::SNIPER, sharedTextures) {}

  void setTexture() override { textures = sharedTextures; }

  void update(ShootParams &p, ProjectileManager &projMan,
              float actorCooldown) override {
    fleeFromPlayer(p);

    p.type = ProjectileType::LONGRANGE;
    p.spec = EnemyDatabase::getWeaponSpec(p.type);
    if (actorCooldown <= 7.0f)
      shootTowardsPlayer(projMan, p);
  }

private:
  void fleeFromPlayer(ShootParams &p) {
    float dist = (float)std::sqrt(std::pow(p.playerPos.x - stats.pos.x, 2) +
                                  std::pow(p.playerPos.y - stats.pos.y, 2));

    if (dist < 300) {
      Vector2 dir = {stats.pos.x - p.playerPos.x, stats.pos.y - p.playerPos.y};
      float len = std::sqrtf(dir.x * dir.x + dir.y * dir.y);

      if (len > 0.0001f) {
        dir.x /= len;
        dir.y /= len;
      }

      stats.pos.x += dir.x * stats.speed * p.dt;
      stats.pos.y += dir.y * stats.speed * p.dt;
    }

    ClampEntities::clamp(stats.pos, (int)stats.size);
  }
};
