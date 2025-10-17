#include "Game.hpp"
#include "Player.hpp"
#include "sound/AudioSystem.hpp"
#include "ui/UILib.hpp"
#include <iostream>
#include <raylib.h>

void restartLevel() {
  AudioSystem::instance().stopMusic();
  AudioSystem::instance().playLevelTrack();
}

void changeMusic() {
  AudioSystem::instance().stopMusic();
  AudioSystem::instance().playTitleTrack();
}

enum class GameState { Playing, Paused, Options, MainMenu };
GameState gameState = GameState::Playing;

void Game::run() {
  Player pwat;
  UILib ui;

  int currentTexture = 0;
  Vector2 pwatPosition = {(float)screenWidth / 2, (float)screenHeight / 2};

  AudioSystem::instance().playLevelTrack();

  bool paused = false;
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    pwat.draw(pwatPosition, currentTexture);
    AudioSystem::instance().updateMusic();

    if (IsKeyPressed(KEY_P)) {
      paused = !paused;
    }

    if (paused) {
      UILib::PauseMenuOpts pauseChoice = ui.pauseMenu();
      AudioSystem::instance().pauseMusic();

      if (IsKeyPressed(KEY_ENTER)) {
        switch (pauseChoice) {
        case UILib::PauseMenuOpts::Resume:
          std::cout << "Resume\n";
          break;
        case UILib::PauseMenuOpts::Restart:
          restartLevel();
          break;
        case UILib::PauseMenuOpts::Options:
          std::cout << "Options\n";
          break;
        case UILib::PauseMenuOpts::BackToMenu:
          changeMusic();
          break;
        default:
          break;
        }
      }
    } else {
      auto state = pwat.playerMovements(currentTexture, pwatPosition);
      currentTexture = state.texture;
      pwatPosition = state.position;
      pwat.playerFootsteps();
      AudioSystem::instance().resumeMusic();
    }

    EndDrawing();
  }
}
