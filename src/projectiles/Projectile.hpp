#pragma once

#include "../entities/Faction.hpp"
#include "ProjectileType.hpp"
#include "WeaponSpec.hpp"
#include <ostream>
#include <raylib.h>

inline std::ostream &operator<<(std::ostream &os, ProjectileType type) {
  switch (type) {
  case ProjectileType::STRAIGHT:
    os << "STRAIGHT";
    break;
  case ProjectileType::LONGRANGE:
    os << "LONGRANGE";
    break;
  case ProjectileType::SLOWCANNON:
    os << "SLOWCANNON";
    break;
  case ProjectileType::ROCKET:
    os << "ROCKET";
    break;
  case ProjectileType::UZI:
    os << "UZI";
    break;
  default:
    os << "UNKNOWN_PROJECTILE";
    break;
  }
  return os;
}

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
    float size = 0.0f;
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
    stats.vel = {dir.x * spec.speed, dir.y * spec.speed};
    stats.cooldown = spec.fireRate;
    stats.size = spec.size;
    stats.lifetime = spec.lifetime;
    stats.damage = spec.damage;
  }

  void expire() { stats.lifetime = 0.0f; }

  bool isActive() { return stats.active; }
  void deactivate() { stats.active = false; }

  float lifetime() const { return stats.lifetime; }
};
