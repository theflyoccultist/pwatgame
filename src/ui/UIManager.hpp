#pragma once

#include "../levels/LevelID.hpp"

namespace UIManager {

void loadUI();
void updateMainMenu(LevelID &currentLevel);
void updateLevelSelection(LevelID &currentlevel);
void updatePlayerHUD(int currentLevel);
void updatePauseMenu();
void updateOptionsMenu();
void updateLostMenu();
void winningMenu(int currentLevel);
void updateCredits();
}; // namespace UIManager
