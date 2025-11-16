#include "MiniBoss.hpp"
#include <raylib.h>

void MiniBoss::update(float dt, [[maybe_unused]] Vector2 playerPos) {
  bossTimer += dt;
}

void MiniBoss::draw() const {
  DrawRectangle(static_cast<int>(position.x), static_cast<int>(position.y),
                stats.size, stats.size, RED);
}
