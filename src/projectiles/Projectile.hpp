#pragma once

#include <raylib.h>

enum class ProjectileType { STRAIGHT, LONGRANGE, COUNT };

class Projectile {
public:
  Projectile(ProjectileType type, Vector2 startPos, Vector2 dir, float spd,
             Vector2 vel, int s, float l, int d)
      : type(type), position(startPos), direction(dir), speed(spd),
        velocity(vel), size(s), lifetime(l), damage(d) {}

  virtual ~Projectile() = default;
  virtual void update(float dt) = 0;
  virtual void draw() const = 0;

  ProjectileType type;
  Vector2 position;
  Vector2 direction;
  float speed;
  Vector2 velocity;
  int size;
  float lifetime;
  int damage;
};
