#pragma once

#include <raylib.h>

namespace PlayerProjectiles {

struct Projectile {
  Vector2 position;
  Vector2 velocity;
  float lifetime = 2.0f;
  static inline int playerAmmo = 100;
};

void init();
void addAmmo(int ammo);
void update(Vector2 playerPosition, Vector2 playerDirection, float dt);
void draw();
} // namespace PlayerProjectiles
