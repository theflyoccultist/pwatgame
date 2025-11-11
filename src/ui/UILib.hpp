#pragma once

namespace UILib {

enum class LostMenuOpts { Restart, Menu, Count };
enum class PauseMenuOpts { Resume, Restart, Options, BackToMenu, Count };
enum class OptionMenuOpts { MusicVol, SfxVol, Count };

void loadUIAssets();

void mainMenu();
void playerHUD();
PauseMenuOpts pauseMenu();
OptionMenuOpts optionsMenu(int musicVol, int sfxVol);
LostMenuOpts losingScreen();

}; // namespace UILib
