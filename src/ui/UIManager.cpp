#include "UIManager.hpp"
#include "../Game.hpp"
#include "../sound/AudioSystem.hpp"
#include "UILib.hpp"
#include <algorithm>

namespace UIManager {

void loadUI() { UILib::loadUIAssets(); }

auto &audio = AudioSystem::instance();

void updateMainMenu() {
  UILib::mainMenu();

  if (IsKeyPressed(KEY_ENTER)) {
    Game::currentState = Game::GameState::Restarting;
    audio.music->stopMusic();
    audio.music->playLevelTrack();
  }
}

void updatePlayerHUD() { UILib::playerHUD(); }

void updatePauseMenu() {
  auto pauseChoice = UILib::pauseMenu();
  audio.music->pauseMusic();

  if (IsKeyPressed(KEY_ENTER)) {
    switch (pauseChoice) {
    case UILib::PauseMenuOpts::Resume:
      Game::currentState = Game::GameState::Playing;
      audio.music->resumeMusic();
      break;
    case UILib::PauseMenuOpts::Restart:
      Game::currentState = Game::GameState::Restarting;
      break;
    case UILib::PauseMenuOpts::Options:
      Game::currentState = Game::GameState::Options;
      break;
    case UILib::PauseMenuOpts::BackToMenu:
      Game::currentState = Game::GameState::MainMenu;
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

  if (IsKeyPressed(KEY_ENTER))
    Game::currentState = Game::GameState::Paused;

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

void updateLostMenu() {
  auto lossChoice = UILib::losingScreen();
  audio.music->pauseMusic();

  if (IsKeyPressed(KEY_ENTER)) {
    switch (lossChoice) {
    case UILib::LostMenuOpts::Restart:
      Game::currentState = Game::GameState::Restarting;
      break;

    case UILib::LostMenuOpts::Menu:
      Game::currentState = Game::GameState::MainMenu;
      audio.music->stopMusic();
      audio.music->playTitleTrack();
      break;

    default:
      break;
    }
  }
}

void winningMenu() { UILib::winningAnim(); }

} // namespace UIManager
