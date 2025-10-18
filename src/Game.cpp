#include "Game.hpp"
#include "Player.hpp"
#include "items/ItemsManager.hpp"
#include "sound/AudioSystem.hpp"
#include "ui/UILib.hpp"
#include <algorithm>
#include <raylib.h>

void updateMainMenu() {
  UILib::mainMenu();
  if (IsKeyPressed(KEY_ENTER)) {
    Game::currentState = Game::GameState::Playing;
    AudioSystem::instance().stopMusic();
    AudioSystem::instance().playLevelTrack();
  }
}

void updatePauseMenu() {
  auto pauseChoice = UILib::pauseMenu();
  AudioSystem::instance().pauseMusic();

  if (IsKeyPressed(KEY_ENTER)) {
    switch (pauseChoice) {
    case UILib::PauseMenuOpts::Resume:
      Game::currentState = Game::GameState::Playing;
      AudioSystem::instance().resumeMusic();
      break;
    case UILib::PauseMenuOpts::Restart:
      Game::currentState = Game::GameState::Playing;
      AudioSystem::instance().stopMusic();
      AudioSystem::instance().playLevelTrack();
      break;
    case UILib::PauseMenuOpts::Options:
      Game::currentState = Game::GameState::Options;
      break;
    case UILib::PauseMenuOpts::BackToMenu:
      Game::currentState = Game::GameState::MainMenu;
      AudioSystem::instance().stopMusic();
      AudioSystem::instance().playTitleTrack();
      break;
    default:
      break;
    }
  }
}

void updateOptionsMenu() {
  static int musicVol = 100;
  static int sfxVol = 100;
  auto optionsChoice = UILib::optionsMenu(musicVol, sfxVol);

  if (IsKeyPressed(KEY_P))
    Game::currentState = Game::GameState::Paused;

  if (IsKeyPressed(KEY_LEFT)) {
    switch (optionsChoice) {
    case UILib::OptionMenuOpts::MusicVol:
      AudioSystem::instance().changeMusicVolume(musicVol -= 5);
      break;
    case UILib::OptionMenuOpts::SfxVol:
      sfxVol -= 5;
      break;
    default:
      break;
    }
  }

  if (IsKeyPressed(KEY_RIGHT)) {
    switch (optionsChoice) {
    case UILib::OptionMenuOpts::MusicVol:
      AudioSystem::instance().changeMusicVolume(musicVol += 5);
      break;
    case UILib::OptionMenuOpts::SfxVol:
      sfxVol += 5;
      break;
    default:
      break;
    }
  }

  musicVol = std::clamp(musicVol, 0, 100);
  sfxVol = std::clamp(sfxVol, 0, 100);
}

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
      updateMainMenu();
      break;

    case GameState::Playing: {
      itemManager.drawItems(ItemCategory::Food);
      itemManager.drawItems(ItemCategory::Drink);
      pwat.draw(pwatPosition, currentTexture);
      auto state = pwat.playerMovements(currentTexture, pwatPosition);
      currentTexture = state.texture;
      pwatPosition = state.position;
      pwat.playerFootsteps();

      if (IsKeyPressed(KEY_P))
        Game::currentState = GameState::Paused;

      break;
    }

    case GameState::Paused:
      updatePauseMenu();
      break;

    case GameState::Options:
      updateOptionsMenu();
      break;
    }

    EndDrawing();
  }
}
