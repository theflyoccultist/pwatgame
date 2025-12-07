#pragma once

#include <cstdint>
namespace UILib {

enum class PauseMenuOpts : uint8_t {
  Resume,
  Restart,
  Options,
  BackToMenu,
  Count
};

enum class OptionMenuOpts : uint8_t { MusicVol, SfxVol, Count };

enum class LostMenuOpts : uint8_t { Restart, Menu, Count };

enum class WinMenuOpts : uint8_t { NextLevel, Restart, Menu, Count };

void loadUIAssets();

void mainMenu();
void playerHUD(int currentLevel);
PauseMenuOpts pauseMenu();
OptionMenuOpts optionsMenu(int musicVol, int sfxVol);
LostMenuOpts losingScreen();
WinMenuOpts winningMenu(int currentLevel);
void CreditsMenu();

}; // namespace UILib
