#pragma once

#include <GameModes.hpp>
#include <cstdint>
#include <projectiles/ProjectileType.hpp>

namespace UILib {

enum class MainMenuOpts : uint8_t { PlayGame, SelectLevel, Help, Count };

enum class LevelOpts : uint8_t {
  Level1,
  Level2,
  Level3,
  Level4,
  BackToMenu,
  Count,
};

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

MainMenuOpts mainMenu();
LevelOpts levelSelection();
void helpHUD();

void levelIntro(int currentLevel);
void playerHUD(int currentLevel);
void weaponHUD(ProjectileType currentProjectile);

PauseMenuOpts pauseMenu();
OptionMenuOpts optionsMenu(int musicVol, int sfxVol);
LostMenuOpts losingScreen(GameModes &gameMode);
WinMenuOpts winningMenu(int currentLevel);
void CreditsMenu();

}; // namespace UILib
