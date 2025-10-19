#pragma once

#include <raylib.h>

namespace PlayerProjectiles {

struct Projectile {
  Vector2 position;
  Vector2 velocity;
  float lifetime = 2.0f;
};

void init();
void update(Vector2 playerPosition, float dt);
void draw();
} // namespace PlayerProjectiles
