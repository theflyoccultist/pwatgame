#include "Player.hpp"
#include "../sound/AudioSystem.hpp"
#include "Game.hpp"

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

    if (playerPosition.x >= Game::screenWidth - pwatSize)
      playerPosition.x = Game::screenWidth - pwatSize;
  }
  if (IsKeyDown(KEY_DOWN)) {
    current = 2;
    playerPosition.y += 2.0f;

    if (playerPosition.y >= Game::screenHeight - pwatSize)
      playerPosition.y = Game::screenHeight - pwatSize;
  }
  if (IsKeyDown(KEY_UP)) {
    current = 3;
    playerPosition.y -= 2.0f;

    if (playerPosition.y <= 0)
      playerPosition.y = 0;
  }
  return {current, playerPosition};
}

void Player::playerFootsteps() {
  if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_UP) ||
      IsKeyDown(KEY_DOWN)) {

    footstepTimer -= GetFrameTime();
    if (footstepTimer <= 0.0f) {
      AudioSystem::instance().playRandSteps();
      footstepTimer = footstepDelay;
    }
  } else {
    footstepTimer = 0.0f;
  }
}
