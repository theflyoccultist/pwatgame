#include "Player.hpp"
#include "Game.hpp"
#include "sound/AudioSystem.hpp"
#include "texture/AssetSystem.hpp"
#include <algorithm>

Player::Player() {
  const std::array<std::string, numPwats> pwatPaths = {
      "../assets/player/pwatleft.png",
      "../assets/player/pwatright.png",
      "../assets/player/pwatup.png",
      "../assets/player/pwatdown.png",
      "../assets/player/pwatleft_up.png",
      "../assets/player/pwatleft_down.png",
      "../assets/player/pwatright_up.png",
      "../assets/player/pwatright_down.png"};

  for (size_t i = 0; i < numPwats; ++i) {
    pwatAssets[i] =
        &AssetSystem::instance().loadTexture(pwatPaths[i], pwatSize, pwatSize);
  }
}

void Player::draw(Vector2 position, int direction) {
  AssetSystem::instance().drawTexture(pwatAssets[direction], position.x,
                                      position.y);
}

PlayerState Player::playerMovements(int current, Vector2 playerPosition) {
  bool left = IsKeyDown(KEY_LEFT);
  bool right = IsKeyDown(KEY_RIGHT);
  bool up = IsKeyDown(KEY_UP);
  bool down = IsKeyDown(KEY_DOWN);

  if (left)
    playerPosition.x -= playerSpeed;

  if (right)
    playerPosition.x += playerSpeed;

  if (up)
    playerPosition.y -= playerSpeed;

  if (down)
    playerPosition.y += playerSpeed;

  playerPosition.x =
      std::clamp(playerPosition.x, 0.0f, (float)(Game::screenWidth - pwatSize));
  playerPosition.y = std::clamp(playerPosition.y, 0.0f,
                                (float)(Game::screenHeight - pwatSize));

  if (left && up)
    current = 4;

  else if (left && down)
    current = 5;

  else if (right && up)
    current = 6;

  else if (right && down)
    current = 7;

  else if (left)
    current = 0;

  else if (right)
    current = 1;

  else if (up)
    current = 2;

  else if (down)
    current = 3;

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
