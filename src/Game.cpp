#include "Game.hpp"
#include "Player.hpp"
#include "sound/AudioSystem.hpp"
#include "ui/PauseMenu.hpp"
#include <raylib.h>

void Game::run() {
  Player pwat;

  PauseMenu ui;

  int currentTexture = 0;
  Vector2 pwatPosition = {(float)screenWidth / 2, (float)screenHeight / 2};

  AudioSystem::instance().playTitleTrack();

  while (!WindowShouldClose()) {
    AudioSystem::instance().updateMusic();

    pwat.playerFootsteps();
    auto state = pwat.playerMovements(currentTexture, pwatPosition);
    currentTexture = state.texture;
    pwatPosition = state.position;

    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("PwatPwat - The Game", 275, 20, 20, DARKPURPLE);
    ui.show();
    pwat.draw(pwatPosition, currentTexture);
    EndDrawing();
  }
}
