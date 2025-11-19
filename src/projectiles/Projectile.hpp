#pragma once

#include "../entities/Faction.hpp"
#include <cstdint>
#include <raylib.h>

enum class ProjectileType : uint8_t {
  STRAIGHT,
  LONGRANGE,
  SLOWCANNON,
  ROCKET,
  COUNT
};

class Projectile {
protected:
  struct ProjectileStats {
    bool active = false;
    Vector2 pos{};
    Vector2 dir{};
    Vector2 vel{};
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

  void expire() { stats.lifetime = 0.0f; }

  bool isActive() { return stats.active; }
  void deactivate() { stats.active = false; }

  float lifetime() const { return stats.lifetime; }
};
