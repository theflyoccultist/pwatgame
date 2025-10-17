#include "Game.hpp"
#include "Player.hpp"
#include "sound/AudioSystem.hpp"
#include "ui/UILib.hpp"
#include <raylib.h>

bool paused = false;

void Game::run() {
  Player pwat;
  UILib ui;

  int currentTexture = 0;
  Vector2 pwatPosition = {(float)screenWidth / 2, (float)screenHeight / 2};

  AudioSystem::instance().playTitleTrack();

  while (!WindowShouldClose()) {
    AudioSystem::instance().updateMusic();

    if (IsKeyPressed(KEY_P)) {
      paused = !paused;
    }

    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("PwatPwat - The Game", 275, 20, 20, DARKPURPLE);
    pwat.draw(pwatPosition, currentTexture);

    if (!paused) {
      AudioSystem::instance().resumeMusic();
      auto state = pwat.playerMovements(currentTexture, pwatPosition);
      currentTexture = state.texture;
      pwatPosition = state.position;
      pwat.playerFootsteps();
    } else {
      ui.pauseMenu();
      AudioSystem::instance().pauseMusic();
    }

    EndDrawing();
  }
}
