#pragma once

#include <raylib.h>

namespace PlayerProjectiles {

struct Projectile {
  Vector2 velocity;
  float lifetime = 2.0f;
};

void init();
void update(Vector2 position, float dt);
void draw(Vector2 position);
void shoot();
} // namespace PlayerProjectiles
