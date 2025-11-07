#pragma once

namespace UILib {

enum class PauseMenuOpts { Resume, Restart, Options, BackToMenu, Count };
enum class OptionMenuOpts { MusicVol, SfxVol, Count };

void loadUIAssets();

constexpr int baseY = 210;
constexpr int spacing = 40;

void mainMenu();
void playerHUD();
PauseMenuOpts pauseMenu();
OptionMenuOpts optionsMenu(int musicVol, int sfxVol);

}; // namespace UILib
