#include "Player.hpp"
#include "Game.hpp"
#include "entities/EnemyManager.hpp"
#include "sound/AudioSystem.hpp"
#include "texture/AssetSystem.hpp"

#include <algorithm>
#include <raylib.h>

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
    pwatAssets[i] = &AssetSystem::instance().loadTexture(
        pwatPaths[i], PlayerState::playerSize, PlayerState::playerSize);
  }
}

void Player::draw(Vector2 position, int direction) {
  AssetSystem::instance().drawTexture(pwatAssets[direction], position.x,
                                      position.y);
}

PlayerState Player::playerMovements(PlayerState state) {
  Vector2 moveDir = {0.0f, 0.0f};

  bool facingLeft = IsKeyDown(KEY_LEFT);
  bool facingRight = IsKeyDown(KEY_RIGHT);
  bool facingUp = IsKeyDown(KEY_UP);
  bool facingDown = IsKeyDown(KEY_DOWN);

  if (facingLeft)
    moveDir.x = -1.0f;

  if (facingRight)
    moveDir.x += 1.0f;

  if (facingUp)
    moveDir.y -= 1.0f;

  if (facingDown)
    moveDir.y += 1.0f;

  state.position.x += moveDir.x * state.playerSpeed * Game::deltaTime;
  state.position.y += moveDir.y * state.playerSpeed * Game::deltaTime;

  state.position.x =
      std::clamp(state.position.x, 0.0f,
                 (float)(Game::screenWidth - PlayerState::playerSize));
  state.position.y =
      std::clamp(state.position.y, 0.0f,
                 (float)(Game::screenHeight - PlayerState::playerSize));

  if (moveDir.x != 0 || moveDir.y != 0)
    state.direction = moveDir;

  if (facingLeft && facingUp)
    state.texture = 4;

  else if (facingLeft && facingDown)
    state.texture = 5;

  else if (facingRight && facingUp)
    state.texture = 6;

  else if (facingRight && facingDown)
    state.texture = 7;

  else if (facingLeft)
    state.texture = 0;

  else if (facingRight)
    state.texture = 1;

  else if (facingUp)
    state.texture = 2;

  else if (facingDown)
    state.texture = 3;

  return state;
}

void Player::playerFootsteps() {
  if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_UP) ||
      IsKeyDown(KEY_DOWN)) {

    footstepTimer -= Game::deltaTime;
    if (footstepTimer <= 0.0f) {
      AudioSystem::instance().playRandSteps();
      footstepTimer = footstepDelay;
    }
  } else {
    footstepTimer = 0.0f;
  }
}
