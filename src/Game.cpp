#include "Game.hpp"
#include "ItemsManager.hpp"
#include "Player.hpp"
#include "sound/AudioSystem.hpp"
#include "ui/UILib.hpp"
#include <raylib.h>

void Game::run() {
  Player pwat;
  static ItemManager itemManager;
  itemManager.populateItems();

  int currentTexture = 0;
  Vector2 pwatPosition = {(float)screenWidth / 2, (float)screenHeight / 2};

  AudioSystem::instance().playTitleTrack();

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    AudioSystem::instance().updateMusic();

    switch (Game::currentState) {
    case GameState::MainMenu:
      UILib::mainMenu();
      if (IsKeyPressed(KEY_ENTER)) {
        Game::currentState = GameState::Playing;
        AudioSystem::instance().stopMusic();
        AudioSystem::instance().playLevelTrack();
      }
      break;

    case GameState::Playing: {
      itemManager.drawItems(ItemCategory::Food);
      itemManager.drawItems(ItemCategory::PowerUp);
      pwat.draw(pwatPosition, currentTexture);
      auto state = pwat.playerMovements(currentTexture, pwatPosition);
      currentTexture = state.texture;
      pwatPosition = state.position;
      pwat.playerFootsteps();

      if (IsKeyPressed(KEY_P))
        Game::currentState = GameState::Paused;

      break;
    }

    case GameState::Paused: {
      auto pauseChoice = UILib::pauseMenu();
      AudioSystem::instance().pauseMusic();

      if (IsKeyPressed(KEY_ENTER)) {
        switch (pauseChoice) {
        case UILib::PauseMenuOpts::Resume:
          Game::currentState = GameState::Playing;
          AudioSystem::instance().resumeMusic();
          break;
        case UILib::PauseMenuOpts::Restart:
          Game::currentState = GameState::Playing;
          AudioSystem::instance().stopMusic();
          AudioSystem::instance().playLevelTrack();
          break;
        case UILib::PauseMenuOpts::Options:
          Game::currentState = GameState::Options;
          break;
        case UILib::PauseMenuOpts::BackToMenu:
          Game::currentState = GameState::MainMenu;
          AudioSystem::instance().stopMusic();
          AudioSystem::instance().playTitleTrack();
          break;
        default:
          break;
        }
      }
      break;
    }

    case GameState::Options:
      UILib::optionsMenu();
      if (IsKeyPressed(KEY_P))
        Game::currentState = GameState::Paused;
      break;
    }

    EndDrawing();
  }
}
