#pragma once

#include "../projectiles/ProjectileManager.hpp"
#include "../utils/Random.hpp"
#include <array>
#include <cmath>
#include <raylib.h>

class Actor {
protected:
  float shootTimer = 0.0f;

  struct ShootParams {
    Vector2 startPos;
    Vector2 playerPos;
    float dt;
    float cooldown;
    ProjectileType type;
  };

private:
  void shoot(ProjectileManager &pm, const ShootParams &p,
             const Vector2 &direction) {
    shootTimer -= p.dt;
    if (shootTimer <= 0.0f) {
      pm.spawn(Faction::Enemy, p.type, p.startPos, direction);
      shootTimer = p.cooldown;
    }
  }

  const bool isX = Random::chance(.5f);

public:
  virtual ~Actor() = default;

  virtual void update(float dt, Vector2 playerPos) = 0;
  virtual void draw() const = 0;

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
