#pragma once

#include "Projectile.hpp"
#include <raylib.h>

class StraightProjectile : public Projectile {
public:
  StraightProjectile(Vector2 startPos, Vector2 dir)
      : Projectile(ProjectileType::STRAIGHT, startPos, dir) {
    position = startPos;
    velocity = {dir.x * speed, dir.y * speed};
    size = 10;
    speed = 700.0f;
    lifetime = 2.0f;
  }

  void update(float dt) override {
    position.x += velocity.x * speed * dt;
    position.y += velocity.y * speed * dt;
    lifetime -= dt;
  };

  void draw() const override {
    DrawCircleV(position, size, BLUE);
    DrawCircleV(position, 4, RED);
  }
};
