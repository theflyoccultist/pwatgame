#pragma once

#include "../projectiles/ProjectileManager.hpp"
#include "PlayerState.hpp"
#include <array>
#include <cstddef>
#include <raylib.h>

class Player {
public:
  Player(ProjectileManager &pm) : projMan(pm) {}
  void init();
  void draw(Vector2 position, int direction);

  PlayerState playerMovements(PlayerState &state, float dt);
  void playerFootsteps(float dt);

  void resetPlayerHealth() { PlayerState::playerHealth = 200; }
  void resetPlayerScore() { PlayerState::playerScore = 0; }
  void resetPlayerAmmo() { PlayerState::playerAmmo = 0; }
  void resetDefaultWeapon();

private:
  static constexpr std::size_t numPwats = 8;
  std::array<Texture2D *, numPwats> pwatAssets;

  float footstepTimer = 0.0f;
  static constexpr float footstepDelay = 0.44f;
  float shootTimer = 0.0f;
  const float pwatCenter = static_cast<float>(PlayerState::playerSize / 2.0);
  void shoot(Vector2 startPosition, Vector2 dir);

  ProjectileManager &projMan;
};
