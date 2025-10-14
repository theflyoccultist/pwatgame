#include "Game.hpp"
#include "Player.hpp"
#include <raylib.h>

void Game::run() {
  Player pwat({
      "../assets/pwatleft.png",
      "../assets/pwatright.png",
      "../assets/pwatdown.png",
      "../assets/pwatup.png",
  });

  float footstepTimer = 0.0f;
  const float footstepDelay = 0.38f;

  int currentTexture = 0;
  Vector2 pwatPosition = {(float)screenWidth / 2, (float)screenHeight / 2};
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    footstepTimer = pwat.playerFootsteps(footstepTimer, footstepDelay);

    auto state = pwat.playerMovements(currentTexture, pwatPosition);
    currentTexture = state.texture;
    pwatPosition = state.position;

    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("PwatPwat - The Game", 275, 20, 20, DARKPURPLE);
    pwat.draw(pwatPosition, currentTexture);
    EndDrawing();
  }
}
