#pragma once

#include "../World.hpp"
#include "Player.hpp"
#include <raylib.h>

class PlayerManager {
public:
  PlayerManager(World &w) : world(w) {}

  PlayerManager &operator=(const PlayerManager &) = delete;
  PlayerManager &operator=(const PlayerManager &&) = delete;

  void loadPlayerTextures() { world.pwat.loadPlayerTextures(); }

  PlayerState initPlayerState() {
    int pwatTexture = 0;
    Vector2 pwatPosition = {static_cast<float>(screenWidth / 2.0),
                            static_cast<float>(screenHeight / 2.0)};
    Vector2 pwatDirection = {-1, 0};
    float pwatSpeed = 600.0f;

    return {pwatTexture, pwatPosition, pwatDirection, pwatSpeed};
  }

  void resetStatus() {
    world.pwat.resetPlayerHealth();
    world.pwat.resetPlayerScore();
    world.pwat.resetPlayerAmmo();
    world.pwat.resetDefaultWeapon();
  }

  void resetPosition(PlayerState &pwatState) {
    pwatState.position = {static_cast<float>(screenWidth / 2.0),
                          static_cast<float>(screenHeight / 2.0)};
  }

  void update(PlayerState &pwatState, float deltaTime) {
    auto state = world.pwat.playerMovements(pwatState, deltaTime);
    pwatState = state;

    world.pwat.draw(pwatState.position, pwatState.texture);
    world.pwat.playerFootsteps(deltaTime);
  }

private:
  World &world;
  const int screenHeight = GetScreenHeight();
  const int screenWidth = GetScreenWidth();
};
