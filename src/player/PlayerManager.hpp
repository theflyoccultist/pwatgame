#pragma once

#include "../World.hpp"
#include "Player.hpp"
#include <raylib.h>

class PlayerManager {
public:
  PlayerManager(World &w) : world(w) {}

  PlayerState init() {
    world.pwat.init();
    int pwatTexture = 0;
    Vector2 pwatPosition = {static_cast<float>(screenWidth / 2.0),
                            static_cast<float>(screenHeight / 2.0)};
    Vector2 pwatDirection = {0, 0};
    return {pwatTexture, pwatPosition, pwatDirection};
  }

  void reset(PlayerState &pwatState) {
    world.pwat.resetPlayerHealth();
    world.pwat.resetPlayerScore();
    world.pwat.resetPlayerAmmo();
    world.pwat.resetDefaultWeapon();
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
