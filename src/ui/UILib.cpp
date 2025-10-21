#include "UILib.hpp"
#include "../Player.hpp"
#include "../entities/EntityManager.hpp"
#include "../projectiles/PlayerProjectiles.hpp"
#include "../texture/AssetSystem.hpp"
#include <algorithm>
#include <array>
#include <format>
#include <raylib.h>
#include <string>

namespace UILib {

std::array<Texture2D *, numAssets> uiAssets;

void loadUIAssets() {
  const std::array<std::string, numAssets> uiPaths = {
      "../assets/ui/pwat_menu.png",
  };

  for (size_t i = 0; i < numAssets; ++i) {
    uiAssets[i] = &AssetSystem::instance().loadTexture(uiPaths[i], 300, 300);
  }
}

void mainMenu() {
  DrawText("PwatPwat - The Game", 275, 20, 20, BLACK);
  DrawText("Press Enter To Play", 165, 300, 40, BLACK);
  AssetSystem::instance().drawTexture(uiAssets[0], 225, 400);
}

void playerHUD() {
  DrawText(TextFormat("Enemies remaining: %d", EntityManager::enemiesCount), 20,
           20, 20, BLACK);
  DrawText(TextFormat("Ammo: %d", PlayerProjectiles::playerAmmo), 20, 50, 20,
           BLACK);
  DrawText(TextFormat("Health: %d", PlayerState::health), 20, 80, 20, BLACK);
  DrawText(TextFormat("Score: %d", PlayerState::score), 20, 110, 20, BLACK);
};

PauseMenuOpts pauseMenu() {
  DrawRectangle(100, 100, 600, 600, YELLOW);
  DrawText("Game Paused", 150, 140, 20, BLACK);

  static int pauseSelectedIndex = 0;

  if (IsKeyPressed(KEY_DOWN))
    pauseSelectedIndex++;
  if (IsKeyPressed(KEY_UP))
    pauseSelectedIndex--;

  pauseSelectedIndex =
      std::clamp(pauseSelectedIndex, 0, (int)PauseMenuOpts::Count - 1);

  int posPauseMenu = baseY + pauseSelectedIndex * spacing;
  DrawRectangle(140, posPauseMenu, 490, 40, GREEN);

  std::array<const char *, 4> menuItems = {"Resume Game", "Restart Level",
                                           "Options", "Back to Menu"};

  int menuPosition = baseY + 10;
  for (auto text : menuItems) {
    DrawText(text, 150, menuPosition, 20, BLACK);
    menuPosition += spacing;
  }

  return static_cast<PauseMenuOpts>(pauseSelectedIndex);
}

OptionMenuOpts optionsMenu(int musicVol, int sfxVol) {
  DrawRectangle(100, 100, 600, 600, ORANGE);
  DrawText("OPTIONS", 150, 140, 20, BLACK);

  static int optionsSelectedIndex = 0;

  if (IsKeyPressed(KEY_DOWN))
    optionsSelectedIndex++;
  if (IsKeyPressed(KEY_UP))
    optionsSelectedIndex--;

  optionsSelectedIndex =
      std::clamp(optionsSelectedIndex, 0, (int)OptionMenuOpts::Count - 1);
  int posOptionsMenu = baseY + optionsSelectedIndex * spacing;
  DrawRectangle(140, posOptionsMenu, 490, 40, PURPLE);

  std::array<std::string, 2> optionItems = {
      std::format("Music : {}%", musicVol),
      std::format("Sound Effects : {}%", sfxVol),
  };

  int menuPosition = baseY + 10;
  for (auto text : optionItems) {
    DrawText(text.c_str(), 150, menuPosition, 20, BLACK);
    menuPosition += spacing;
  }

  return static_cast<OptionMenuOpts>(optionsSelectedIndex);
}

} // namespace UILib
