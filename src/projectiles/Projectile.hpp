#pragma once

#include <raylib.h>

enum class ProjectileType { STRAIGHT, LONGRANGE, COUNT };

class Projectile {
public:
  Projectile(ProjectileType type, Vector2 startPos, Vector2 dir)
      : type(type), position(startPos), direction(dir) {}

  ProjectileType type;
  Vector2 position;
  Vector2 direction;
  Vector2 velocity;
  int size;
  float speed;
  float lifetime;

  virtual ~Projectile() = default;
  virtual void update(float dt) = 0;
  virtual void draw() const = 0;
};
