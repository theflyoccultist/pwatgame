#pragma once

#include "Player.hpp"
#include <raylib.h>

class PlayerManager {
public:
  PlayerState init() {
    int pwatTexture = 0;
    Vector2 pwatPosition = {static_cast<float>(screenWidth / 2.0),
                            static_cast<float>(screenHeight / 2.0)};
    Vector2 pwatDirection = {0.0f, 0.0f};
    return {pwatTexture, pwatPosition, pwatDirection};
  }

  void reset(PlayerState &pwatState) {
    pwat.resetPlayerHealth();
    pwat.resetPlayerScore();
    pwat.resetPlayerAmmo();
    pwatState.position = {static_cast<float>(screenWidth / 2.0),
                          static_cast<float>(screenHeight / 2.0)};
  }

  void update(float deltaTime, PlayerState &pwatState) {
    auto state = pwat.playerMovements(pwatState, deltaTime);
    pwatState = state;

    pwat.draw(pwatState.position, pwatState.texture);
    pwat.playerFootsteps(deltaTime);
  }

private:
  Player pwat;
  int screenHeight = GetScreenHeight();
  int screenWidth = GetScreenWidth();
};
