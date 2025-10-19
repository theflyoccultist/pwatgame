#include "PlayerProjectiles.hpp"
#include "../Player.hpp"
#include <algorithm>
#include <vector>

namespace PlayerProjectiles {

namespace {

std::vector<Projectile> projectiles;
int ammoCount = 100;
float shootCooldown = 0.3f;
float shootTimer = 0.0f;

} // namespace

void init() {
  projectiles.clear();
  ammoCount = 100;
  shootTimer = 0.0f;
}

void shoot(Vector2 startPosition) {
  if (ammoCount <= 0 || shootTimer > 0.0f)
    return;

  Projectile p;
  p.position = startPosition;
  p.velocity = {400, 0};
  p.lifetime = 2.0f;
  projectiles.push_back(p);

  ammoCount--;
  shootTimer = shootCooldown;
}

void update(Vector2 playerPosition, float dt) {
  shootTimer = std::max(0.0f, shootTimer - dt);

  if (IsKeyPressed(KEY_SPACE))
    shoot(playerPosition);

  for (auto &p : projectiles) {
    p.position.x += p.velocity.x * dt;
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

  DrawText(TextFormat("Ammo: %d", ammoCount), 20, 20, 20, BLACK);
}

} // namespace PlayerProjectiles
