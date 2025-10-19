#pragma once

#include <cstddef>
namespace UILib {

enum class PauseMenuOpts { Resume, Restart, Options, BackToMenu, Count };
enum class OptionMenuOpts { MusicVol, SfxVol, Count };

constexpr std::size_t numAssets = 1;
void loadUIAssets();

constexpr int baseY = 210;
constexpr int spacing = 40;

void mainMenu();
void playerHUD();
PauseMenuOpts pauseMenu();
OptionMenuOpts optionsMenu(int musicVol, int sfxVol);

}; // namespace UILib
