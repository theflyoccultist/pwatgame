#include "PlayerProjectiles.hpp"
#include <algorithm>
#include <vector>

namespace PlayerProjectiles {

namespace {

std::vector<Projectile> projectiles;
float shootCooldown = 0.3f;
float shootTimer = 0.0f;

} // namespace

void init() {
  projectiles.clear();
  shootTimer = 0.0f;
  PlayerProjectiles::playerAmmo = 100;
}

void shoot(Vector2 startPosition, Vector2 dir) {
  if (PlayerProjectiles::playerAmmo <= 0 || shootTimer > 0.0f)
    return;

  Projectile p;
  p.position = startPosition;
  p.velocity = {dir.x * 400.0f, dir.y * 400.0f};
  p.lifetime = 2.0f;
  projectiles.push_back(p);

  PlayerProjectiles::playerAmmo--;
  shootTimer = shootCooldown;
}

void addAmmo(int ammo) { PlayerProjectiles::playerAmmo += ammo; }

void update(Vector2 playerPosition, Vector2 playerDirection, float dt) {
  shootTimer = std::max(0.0f, shootTimer - dt);

  if (IsKeyPressed(KEY_SPACE))
    shoot(playerPosition, playerDirection);

  for (auto &p : projectiles) {
    p.position.x += p.velocity.x * dt;
    p.position.y += p.velocity.y * dt;
    p.lifetime -= dt;
  }

  projectiles.erase(
      std::remove_if(projectiles.begin(), projectiles.end(),
                     [](const Projectile &p) { return p.lifetime <= 0; }),
      projectiles.end());
}

void draw() {
  for (auto &p : projectiles) {
    DrawCircleV(p.position, 10, BLUE);
    DrawCircleV(p.position, 4, RED);
  }
}

} // namespace PlayerProjectiles
