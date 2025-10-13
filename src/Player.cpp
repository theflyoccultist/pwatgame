#include "Player.hpp"
#include <raylib.h>

PlayerState Player::playerMovements(int current, Vector2 playerPosition) {
  if (IsKeyDown(KEY_LEFT)) {
    current = 0;
    playerPosition.x -= 2.0f;
  }
  if (IsKeyDown(KEY_RIGHT)) {
    current = 1;
    playerPosition.x += 2.0f;
  }
  if (IsKeyDown(KEY_DOWN)) {
    current = 2;
    playerPosition.y += 2.0f;
  }
  if (IsKeyDown(KEY_UP)) {
    current = 3;
    playerPosition.y -= 2.0f;
  }
  return {current, playerPosition};
}
