#include "Player.hpp"
#include "Game.hpp"
#include <raylib.h>

Game g;

PlayerState Player::playerMovements(int current, Vector2 playerPosition) {
  if (IsKeyDown(KEY_LEFT)) {
    current = 0;
    playerPosition.x -= 2.0f;

    if (playerPosition.x <= 0)
      playerPosition.x = 0;
  }
  if (IsKeyDown(KEY_RIGHT)) {
    current = 1;
    playerPosition.x += 2.0f;

    if (playerPosition.x >= g.screenWidth - pwatSize)
      playerPosition.x = g.screenWidth - pwatSize;
  }
  if (IsKeyDown(KEY_DOWN)) {
    current = 2;
    playerPosition.y += 2.0f;

    if (playerPosition.y >= g.screenHeight - pwatSize)
      playerPosition.y = g.screenHeight - pwatSize;
  }
  if (IsKeyDown(KEY_UP)) {
    current = 3;
    playerPosition.y -= 2.0f;

    if (playerPosition.y <= 0)
      playerPosition.y = 0;
  }
  return {current, playerPosition};
}
