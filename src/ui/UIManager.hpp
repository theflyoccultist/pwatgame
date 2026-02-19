#pragma once

#include <GameModes.hpp>
#include <levels/LevelID.hpp>
#include <projectiles/ProjectileType.hpp>

namespace UIManager {

void loadUITextures();
void updateMainMenu(LevelID &currentLevel, GameModes &gameMode);
void updateLevelSelection(LevelID &currentlevel);
void updateHelpMenu();

void updateLevelIntro(int currentLevel);
void updatePlayerHUD(int currentLevel);
void updateweaponHUD(ProjectileType currentProjectile);

void updatePauseMenu();
void updateOptionsMenu();
void updateLostMenu(LevelID &currentLevel, GameModes &gameMode);
void winningMenu(int currentLevel, float dt);
void updateCredits();
}; // namespace UIManager
