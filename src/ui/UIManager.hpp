#pragma once

namespace UIManager {

void loadUI();
void updateMainMenu();
void updatePlayerHUD(int currentLevel);
void updatePauseMenu();
void updateOptionsMenu();
void updateLostMenu();
void winningMenu(int currentLevel);
void updateCredits();
}; // namespace UIManager
