#include "UIManager.hpp"
#include "../Game.hpp"
#include "../sound/AudioSystem.hpp"
#include "UILib.hpp"
#include <algorithm>
#include <iostream>
#include <raylib.h>

namespace UIManager {

void loadUITextures() { UILib::loadUIAssets(); }

auto &audio = AudioSystem::instance();

void updateMainMenu(LevelID &currentLevel, GameModes &gamemode) {
  auto menuChoice = UILib::mainMenu();

  if (IsKeyPressed(KEY_ENTER)) {
    switch (menuChoice) {
    case UILib::MainMenuOpts::PlayGame:
      audio.sfx->startLevel();
      currentLevel = LevelID::Level1;
      gamemode = GameModes::Dealthless;
      Game::currentState = GameState::Restarting;
      break;
    case UILib::MainMenuOpts::SelectLevel:
      audio.sfx->menuEnter();
      gamemode = GameModes::LevelSelection;
      Game::currentState = GameState::LevelSelection;
      break;
    case UILib::MainMenuOpts::Help:
      audio.sfx->menuEnter();
      Game::currentState = GameState::DisplayHelp;
    default:
      break;
    }
  }
}

void updateLevelSelection(LevelID &currentLevel) {
  auto levelChoice = UILib::levelSelection();

  if (IsKeyPressed(KEY_ENTER)) {
    switch (levelChoice) {
    case UILib::LevelOpts::Level1:
      audio.sfx->startLevel();
      currentLevel = LevelID::Level1;
      Game::currentState = GameState::Restarting;
      break;
    case UILib::LevelOpts::Level2:
      currentLevel = LevelID::Level2;
      audio.sfx->startLevel();
      Game::currentState = GameState::Restarting;
      break;
    case UILib::LevelOpts::Level3:
      currentLevel = LevelID::Level3;
      audio.sfx->startLevel();
      Game::currentState = GameState::Restarting;
      break;
    case UILib::LevelOpts::Level4:
      currentLevel = LevelID::Level4;
      audio.sfx->startLevel();
      Game::currentState = GameState::Restarting;
      break;
    case UILib::LevelOpts::BackToMenu:
      audio.sfx->menuEnter();
      Game::currentState = GameState::MainMenu;
      break;
    default:
      break;
    }
  }
}

void updateHelpMenu() {
  UILib::helpHUD();
  if (IsKeyPressed(KEY_ENTER)) {
    audio.sfx->menuEnter();
    Game::currentState = GameState::MainMenu;
  }
}

void updateLevelIntro(int currentLevel) {
  UILib::levelIntro(currentLevel);
  if (IsKeyPressed(KEY_ENTER)) {
    Game::currentState = GameState::Playing;
  }
}

void updatePlayerHUD(int currentLevel) { UILib::playerHUD(currentLevel); }

void updateweaponHUD(ProjectileType currentProjectile) {
  UILib::weaponHUD(currentProjectile);
}

void updatePauseMenu() {
  auto pauseChoice = UILib::pauseMenu();
  audio.music->pauseMusic();

  if (IsKeyPressed(KEY_ENTER)) {
    audio.sfx->menuEnter();
    switch (pauseChoice) {
    case UILib::PauseMenuOpts::Resume:
      Game::currentState = GameState::Playing;
      audio.music->resumeMusic();
      break;
    case UILib::PauseMenuOpts::Restart:
      Game::currentState = GameState::Restarting;
      break;
    case UILib::PauseMenuOpts::Options:
      Game::currentState = GameState::Options;
      break;
    case UILib::PauseMenuOpts::BackToMenu:
      Game::currentState = GameState::MainMenu;
      audio.music->stopMusic();
      audio.music->playTitleTrack();
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

  if (IsKeyPressed(KEY_ENTER)) {
    audio.sfx->menuEnter();
    Game::currentState = GameState::Paused;
  }

  if (IsKeyPressed(KEY_LEFT)) {
    switch (optionsChoice) {
    case UILib::OptionMenuOpts::MusicVol:
      audio.music->changeMusicVolume(musicVol -= 5);
      break;
    case UILib::OptionMenuOpts::SfxVol:
      audio.sfx->changeSfxVolume(sfxVol -= 5);
      break;
    default:
      break;
    }
  }

  if (IsKeyPressed(KEY_RIGHT)) {
    switch (optionsChoice) {
    case UILib::OptionMenuOpts::MusicVol:
      audio.music->changeMusicVolume(musicVol += 5);
      break;
    case UILib::OptionMenuOpts::SfxVol:
      audio.sfx->changeSfxVolume(sfxVol += 5);
      break;
    default:
      break;
    }
  }

  musicVol = std::clamp(musicVol, 0, 100);
  sfxVol = std::clamp(sfxVol, 0, 100);
}

bool lostTrigger = true;

void updateLostMenu(LevelID &currentLevel, GameModes &gameMode) {
  auto lossChoice = UILib::losingScreen(gameMode);
  audio.music->pauseMusic();

  if (lostTrigger) {
    audio.sfx->lostBeeps();
    lostTrigger = false;
  }

  if (IsKeyPressed(KEY_ENTER)) {
    audio.sfx->menuEnter();
    lostTrigger = true;

    switch (lossChoice) {
    case UILib::LostMenuOpts::Restart:
      if (gameMode == GameModes::Dealthless) {
        currentLevel = LevelID::Level1;
      }

      std::cout << "UIManager - You lost! Gamemode: " << gameMode << "\n"
                << "Restarting at level: " << currentLevel << "\n";
      Game::currentState = GameState::Restarting;
      break;

    case UILib::LostMenuOpts::Menu:
      Game::currentState = GameState::MainMenu;
      audio.music->stopMusic();
      audio.music->playTitleTrack();
      break;

    default:
      break;
    }
  }
}

float bounceTimer = 0.0f;
const float bounceDelay = 0.695f;

void winningMenu(int currentLevel, float dt) {
  bounceTimer -= dt;
  if (bounceTimer <= 0.0f) {
    audio.sfx->winBounce();
    bounceTimer = bounceDelay;
  }

  auto winChoice = UILib::winningMenu(currentLevel);
  if (IsKeyPressed(KEY_ENTER)) {
    audio.sfx->menuEnter();
    switch (winChoice) {
    case UILib::WinMenuOpts::NextLevel:
      if (currentLevel == 4) {
        Game::currentState = GameState::ShowCredits;
      } else {
        Game::currentState = GameState::NextLevel;
      }
      break;

    case UILib::WinMenuOpts::Restart:
      Game::currentState = GameState::Restarting;
      break;

    case UILib::WinMenuOpts::Menu:
      Game::currentState = GameState::MainMenu;
      audio.music->stopMusic();
      audio.music->playTitleTrack();
      break;

    default:
      break;
    }
  }
}

void updateCredits() {
  UILib::CreditsMenu();

  if (IsKeyPressed(KEY_ENTER)) {
    audio.sfx->menuEnter();
    Game::currentState = GameState::MainMenu;
    audio.music->stopMusic();
    audio.music->playTitleTrack();
  }
}

} // namespace UIManager
