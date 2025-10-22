#pragma once

#include <raylib.h>
#include <vector>

namespace PlayerProjectiles {
inline int playerAmmo;
inline float size;

struct Projectile {
  Vector2 position;
  Vector2 velocity;
  float lifetime = 2.0f;
};

void init();
void addAmmo(int ammo);
void resetAmmo();
void update(Vector2 playerPosition, Vector2 playerDirection, float dt);
void draw();

const std::vector<Vector2> getProjectilePositions();
} // namespace PlayerProjectiles
