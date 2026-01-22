#pragma once

#include "../projectiles/ProjectileManager.hpp"
#include "../utils/Random.hpp"
#include "Faction.hpp"
#include <array>
#include <cmath>
#include <raylib.h>

class Actor {
public:
  float shootTimer = 0.0f;

  struct ShootParams {
    Vector2 startPos;
    Vector2 playerPos;
    float dt;
    ProjectileType type;
    WeaponSpec spec;
  };

private:
  void shoot(ProjectileManager &pm, const ShootParams &p,
             const Vector2 &direction) {
    shootTimer -= p.dt;
    if (shootTimer <= 0.0f) {
      pm.spawn({Faction::Enemy, p.type, p.startPos, direction, p.spec});
      shootTimer = p.spec.fireRate;
    }
  }

  const bool isX = Random::chance(.5f);

public:
  virtual ~Actor() = default;

  virtual void draw() const = 0;

  virtual void update(ShootParams &p, ProjectileManager &projMan,
                      float actorCooldown) = 0;

  void shootTowardsPlayer(ProjectileManager &pm, const ShootParams &p) {
    Vector2 direction = {p.playerPos.x - p.startPos.x,
                         p.playerPos.y - p.startPos.y};

    float len =
        std::sqrt(direction.x * direction.x + direction.y * direction.y);
    if (len != 0) {
      direction.x /= len;
      direction.y /= len;
    }

    shoot(pm, p, direction);
  }

  void shootInVoid(ProjectileManager &pm, const ShootParams &p) {
    Vector2 direction;
    isX ? direction = {-1, 0} : direction = {0, -1};

    shoot(pm, p, direction);
  }

  void shootRadialBurst(ProjectileManager &pm, const ShootParams &p,
                        int count) {
    const float step = 2.0f * PI / (float)count;

    for (int i = 0; i < count; ++i) {
      float angle = (float)i * step;
      Vector2 dir = {cosf(angle), sinf(angle)};
      shoot(pm, p, dir);
    }
  }

  void shootGarbageBurst(ProjectileManager &pm, const ShootParams &p) {
    float step = Random::rangeFloat(1.0f, 4.0f) * PI / 3;

    for (int i = 0; i < Random::rangeInt(2, 10); ++i) {
      Vector2 dir = {cosf((float)i * step), sinf((float)i * step)};
      shoot(pm, p, dir);
    }
  }

  void shootFractals(ProjectileManager &pm, const ShootParams &p,
                     float actorCooldown) {
    float yMovement = std::sinf(std::cosf(actorCooldown));
    float xMovement = std::cosf(std::sinf(actorCooldown));

    shoot(pm, p, {xMovement, yMovement});
    shoot(pm, p, {-xMovement, yMovement});
    shoot(pm, p, {xMovement, -yMovement});
    shoot(pm, p, {-xMovement, -yMovement});
  }

  void shootDiagonally(ProjectileManager &pm, const ShootParams &p) {
    shoot(pm, p, {0, 1});
    shoot(pm, p, {1, 1});
  }

  void shootJavaJIT(ProjectileManager &pm, ShootParams &p, float &shootAccel) {
    Vector2 direction = {p.playerPos.x - p.startPos.x,
                         p.playerPos.y - p.startPos.y};

    float len =
        std::sqrt(direction.x * direction.x + direction.y * direction.y);
    if (len != 0) {
      direction.x /= len;
      direction.y /= len;
    }

    shootTimer -= p.dt;
    if ((shootTimer - shootAccel) <= 0.0f) {
      pm.spawn({Faction::Enemy, p.type, p.startPos, direction, p.spec});
      shootTimer = p.spec.fireRate;
      shootAccel += 0.025f;
    }
  }

  void shootThreadJIT(ProjectileManager &pm, ShootParams &p,
                      float actorCooldown) {
    Vector2 direction = {p.playerPos.x - p.startPos.x,
                         p.playerPos.y - p.startPos.y};

    float len =
        std::sqrt(direction.x * direction.x + direction.y * direction.y);
    if (len != 0) {
      direction.x /= len;
      direction.y /= len;
    }

    shootTimer -= p.dt;
    if ((shootTimer - actorCooldown) <= 0.0f) {
      pm.spawn({Faction::Enemy, p.type, p.startPos, direction, p.spec});
      shootTimer = p.spec.fireRate;
    }
  }

protected:
  const Texture2D *
  chooseTexture(float ratio, const std::array<Texture2D *, 3> &textures) const {
    if (textures[0] == nullptr)
      return nullptr;
    if (ratio > 0.66f)
      return textures[0];
    if (ratio > 0.33f)
      return textures[1];
    return textures[2];
  }

  const Color healthbarColor(float ratio) const {
    if (ratio > 0.66f)
      return GREEN;
    if (ratio > 0.33f)
      return YELLOW;
    return RED;
  }
};
