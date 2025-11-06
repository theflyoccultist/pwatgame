#pragma once

#include "Player.hpp"
#include <raylib.h>

class PlayerManager {
public:
  PlayerState init() {
    int pwatTexture = 0;
    Vector2 pwatPosition = {static_cast<float>(screenWidth / 2.0),
                            static_cast<float>(screenHeight / 2.0)};
    Vector2 pwatDirection = {0, 0};
    return {pwatTexture, pwatPosition, pwatDirection};
  }

  void reset(PlayerState &pwatState) {
    pwat.resetPlayerHealth();
    pwat.resetPlayerScore();
    pwat.resetPlayerAmmo();
    pwatState.position = {static_cast<float>(screenWidth / 2.0),
                          static_cast<float>(screenHeight / 2.0)};
  }

  void update(PlayerState &pwatState, float deltaTime) {
    auto state = pwat.playerMovements(pwatState, deltaTime);
    pwatState = state;

    pwat.draw(pwatState.position, pwatState.texture);
    pwat.playerFootsteps(deltaTime);
  }

private:
  Player pwat;
  const int screenHeight = GetScreenHeight();
  const int screenWidth = GetScreenWidth();
};
