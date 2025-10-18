#include "UIManager.hpp"
#include "../Game.hpp"
#include "../sound/AudioSystem.hpp"
#include "UILib.hpp"
#include <algorithm>

namespace UIManager {

void loadUI() { UILib::loadUIAssets(); }

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

  if (IsKeyPressed(KEY_ENTER))
    Game::currentState = Game::GameState::Paused;

  if (IsKeyPressed(KEY_LEFT)) {
    switch (optionsChoice) {
    case UILib::OptionMenuOpts::MusicVol:
      AudioSystem::instance().changeMusicVolume(musicVol -= 5);
      break;
    case UILib::OptionMenuOpts::SfxVol:
      AudioSystem::instance().changeSfxVolume(sfxVol -= 5);
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
      AudioSystem::instance().changeSfxVolume(sfxVol += 5);
      break;
    default:
      break;
    }
  }

  musicVol = std::clamp(musicVol, 0, 100);
  sfxVol = std::clamp(sfxVol, 0, 100);
}

} // namespace UIManager
