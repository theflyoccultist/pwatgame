#pragma once

#include <cstdint>
namespace UILib {

enum class LostMenuOpts : uint8_t { Restart, Menu, Count };

enum class PauseMenuOpts : uint8_t {
  Resume,
  Restart,
  Options,
  BackToMenu,
  Count
};

enum class OptionMenuOpts : uint8_t { MusicVol, SfxVol, Count };

void loadUIAssets();

void mainMenu();
void playerHUD();
PauseMenuOpts pauseMenu();
OptionMenuOpts optionsMenu(int musicVol, int sfxVol);
LostMenuOpts losingScreen();

}; // namespace UILib
