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
    Vector2 startPos;
    Vector2 dir;
    Vector2 vel;
    float size;
    float lifetime;
    int damage;
  };

public:
  Projectile(Faction f, ProjectileType type, ProjectileStats stats)
      : faction(f), type(type), position(stats.startPos), direction(stats.dir),
        velocity(stats.vel), size(stats.size), lifetime(stats.lifetime),
        damage(stats.damage) {}

  virtual ~Projectile() = default;

  virtual void update(float dt) {
    position.x += velocity.x * dt;
    position.y += velocity.y * dt;
    lifetime -= dt;
  };

  virtual void draw() const = 0;

  void expire() { lifetime = 0.0f; }

  Faction faction;
  ProjectileType type;
  Vector2 position;
  Vector2 direction;
  float speed;
  Vector2 velocity;
  float size;
  float lifetime;
  int damage;
};
