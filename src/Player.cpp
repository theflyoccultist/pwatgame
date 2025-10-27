#include "Player.hpp"
#include "projectiles/ProjectileManager.hpp"
#include "sound/AudioSystem.hpp"
#include "texture/AssetSystem.hpp"
#include "utils/clampEntities.hpp"

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

  shootTimer = 0.0f;
  PlayerState::playerAmmo = 500;
}

void Player::shoot(Vector2 startPosition, Vector2 dir) {
  if (PlayerState::playerAmmo <= 0 || shootTimer > 0.0f)
    return;

  ProjectileManager::instance().spawn(ProjectileType::STRAIGHT, startPosition,
                                      dir);

  PlayerState::playerAmmo--;
  shootTimer = shootCooldown;
}

void Player::draw(Vector2 position, int direction) {
  AssetSystem::instance().drawTexture(pwatAssets[direction], position.x,
                                      position.y);
}

PlayerState Player::playerMovements(PlayerState state, float dt) {
  Vector2 moveDir = {0.0f, 0.0f};

  bool facingLeft = IsKeyDown(KEY_LEFT);
  bool facingRight = IsKeyDown(KEY_RIGHT);
  bool facingUp = IsKeyDown(KEY_UP);
  bool facingDown = IsKeyDown(KEY_DOWN);
  bool shooting = IsKeyDown(KEY_SPACE);

  if (facingLeft)
    moveDir.x = -1.0f;

  if (facingRight)
    moveDir.x += 1.0f;

  if (facingUp)
    moveDir.y -= 1.0f;

  if (facingDown)
    moveDir.y += 1.0f;

  shootTimer = std::max(0.0f, shootTimer - dt);

  state.position.x += moveDir.x * state.playerSpeed * dt;
  state.position.y += moveDir.y * state.playerSpeed * dt;

  ClampEntities::clamp(state.position, PlayerState::playerSize);

  if (moveDir.x != 0 || moveDir.y != 0)
    state.direction = moveDir;

  if (shooting)
    shoot({state.position.x + pwatCenter, state.position.y + pwatCenter},
          state.direction);

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

void Player::playerFootsteps(float dt) {
  if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_UP) ||
      IsKeyDown(KEY_DOWN)) {

    footstepTimer -= dt;
    if (footstepTimer <= 0.0f) {
      AudioSystem::instance().playRandSteps();
      footstepTimer = footstepDelay;
    }
  } else {
    footstepTimer = 0.0f;
  }
}
