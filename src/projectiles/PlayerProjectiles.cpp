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

void shoot() {
  if (ammoCount <= 0 || shootTimer > 0.0f)
    return;

  Projectile p;
  p.velocity = {400, 0};
  projectiles.push_back(p);
  ammoCount--;
  shootTimer = shootCooldown;
}

void update(Vector2 position, float dt) {
  shootTimer = std::max(0.0f, shootTimer - dt);

  if (IsKeyPressed(KEY_SPACE))
    shoot();

  for (auto &p : projectiles) {
    position.x += p.velocity.x * dt;
    p.lifetime -= dt;
  }

  projectiles.erase(
      std::remove_if(projectiles.begin(), projectiles.end(),
                     [](const Projectile &p) { return p.lifetime <= 0; }),
      projectiles.end());
}

void draw(Vector2 position) {
  DrawCircleV(position, 10, BLUE);
  DrawCircleV(position, 4, RED);

  DrawText(TextFormat("Ammo: %d", ammoCount), 20, 20, 20, BLACK);
}

} // namespace PlayerProjectiles
