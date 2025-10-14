#include "Game.hpp"
#include "../sound/AudioSystem.hpp"
#include "Player.hpp"
#include <raylib.h>

void Game::run() {
  Player pwat({
      "../assets/pwatleft.png",
      "../assets/pwatright.png",
      "../assets/pwatdown.png",
      "../assets/pwatup.png",
  });

  AudioSystem audio;

  int currentTexture = 0;
  Vector2 pwatPosition = {(float)screenWidth / 2, (float)screenHeight / 2};
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    if (GetKeyPressed() == KEY_LEFT)
      audio.playRandSteps();

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
