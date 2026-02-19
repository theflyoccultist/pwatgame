#pragma once

#include <entities/Enemy.hpp>
#include <entities/EnemyDatabase.hpp>
#include <utils/clampEntities.hpp>

class Godsip : public Enemy {
public:
  static std::array<Texture2D *, 3> sharedTextures;
  Godsip() : Enemy(EnemyType::GODSIP, sharedTextures) {}

  void setTexture() override { textures = sharedTextures; }

  void update(ShootParams &p, ProjectileManager &projMan,
              float actorCooldown) override {
    float godsipCooldown = std::fmod(actorCooldown, 4.0f);
    dashTimer += p.dt;

    if (godsipCooldown <= 0.8f) {
      stats.pos.x += (stats.initialPos.x - stats.pos.x) * 0.25f;
      stats.pos.y += (stats.initialPos.y - stats.pos.y) * 0.25f;
    }

    if (!isDashing) {
      if (dashTimer >= actorCooldown) {
        Vector2 rawDir = {p.playerPos.x - stats.pos.x,
                          p.playerPos.y - stats.pos.y};
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

      if (godsipCooldown >= 3.0f) {
        p.type = ProjectileType::RECON;
        p.spec = EnemyDatabase::getWeaponSpec(p.type);
        shootTowardsPlayer(projMan, p);
      }
    }

    if (isDashing) {
      stats.pos.x += dashDir.x * stats.speed * p.dt * 12;
      stats.pos.y += dashDir.y * stats.speed * p.dt * 12;
      ClampEntities::clamp(stats.pos, (int)stats.size);

      if (dashTimer >= dashDuration) {
        isDashing = false;
        dashTimer = 0.f;
      }
    }
  };

private:
  float dashTimer = 0.f;
  float dashDuration = 1.5f;
  Vector2 dashDir{};
  bool isDashing = false;
};
