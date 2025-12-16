#pragma once

#include "../levels/LevelID.hpp"
#include "../projectiles/ProjectileType.hpp"

namespace UIManager {

void loadUI();
void updateMainMenu(LevelID &currentLevel);
void updateLevelSelection(LevelID &currentlevel);

void updateLevelIntro(int currentLevel);
void updatePlayerHUD(int currentLevel);
void updateweaponHUD(ProjectileType currentProjectile);

void updatePauseMenu();
void updateOptionsMenu();
void updateLostMenu();
void winningMenu(int currentLevel);
void updateCredits();
}; // namespace UIManager
