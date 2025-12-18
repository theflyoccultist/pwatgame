#pragma once

#include "../entities/Faction.hpp"
#include "ProjectileType.hpp"
#include "TextureRegistry.hpp"
#include "WeaponSpec.hpp"
#include <iostream>
#include <raylib.h>

inline const char *toString(ProjectileType type) {
  switch (type) {
  case ProjectileType::STRAIGHT:
    return "STRAIGHT";
  case ProjectileType::LONGRANGE:
    return "LONGRANGE";
  case ProjectileType::SLOWCANNON:
    return "SLOWCANNON";
  case ProjectileType::ROCKET:
    return "ROCKET";
  case ProjectileType::UZI:
    return "UZI";
  case ProjectileType::GRENADE:
    return "GRENADE";
  case ProjectileType::HELLFIRE:
    return "HELLFIRE";
  default:
    return "UNKNOWN_PROJECTILE";
  }
}

class Projectile {
protected:
  struct ProjectileStats {
    bool active = false;
    Vector2 pos{};
    Vector2 dir{};
    Vector2 vel{};
    float cooldown = 0.0f;
    int size = 0;
    float lifetime = 0.0f;
    int damage = 0;
  };

public:
  ProjectileStats stats;
  Faction faction;
  ProjectileType type;

  Projectile(Faction f, ProjectileType t) : faction(f), type(t) {}

  virtual ~Projectile() = default;

  virtual void update(float dt) {
    stats.pos.x += stats.vel.x * dt;
    stats.pos.y += stats.vel.y * dt;
    stats.lifetime -= dt;
  };

  virtual void draw() const = 0;

  void reset(Faction f, Vector2 pos, Vector2 dir, const WeaponSpec &spec) {
    stats.active = true;
    faction = f;
    stats.pos = pos;
    stats.dir = dir;
    stats.vel = {dir.x * (float)spec.speed, dir.y * (float)spec.speed};
    stats.cooldown = spec.fireRate;
    stats.size = spec.size;
    stats.lifetime = spec.lifetime;
    stats.damage = spec.damage;
  }

  void expire() { stats.lifetime = 0.0f; }

  bool isActive() const { return stats.active; }
  void deactivate() { stats.active = false; }

  float lifetime() const { return stats.lifetime; }
};
