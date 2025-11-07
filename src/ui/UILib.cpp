#include "UILib.hpp"
#include "../entities/EnemyManager.hpp"
#include "../texture/AssetSystem.hpp"
#include <algorithm>
#include <array>
#include <format>
#include <raylib.h>
#include <string>
#include <unordered_map>
#include <vector>

namespace UILib {

enum class AssetType { Background, PwatMenu };

std::unordered_map<AssetType, std::vector<std::string>> assetBank;
std::vector<Texture2D *> uiAssets;

void loadUIAssets() {
  assetBank[AssetType::Background] = {
      "../assets/ui/bkg1.png",
      "../assets/ui/bkg2.png",
      "../assets/ui/bkg3.png",
      "../assets/ui/bkg4.png",
  };

  assetBank[AssetType::PwatMenu] = {
      "../assets/ui/pwat_menu.png",
  };

  auto &asset = AssetSystem::instance();

  for (auto &bkg : assetBank[AssetType::Background]) {
    uiAssets.push_back(&asset.loadTexture(bkg, 800, 800));
  }

  uiAssets.push_back(
      &asset.loadTexture(assetBank[AssetType::PwatMenu][0], 300, 300));
}

void mainMenu() {
  AssetSystem::instance().drawTexture(uiAssets[0], 0, 0);
  AssetSystem::instance().drawTexture(uiAssets[4], 225, 400);
  DrawText("PwatPwat - The Game", 275, 20, 20, BLACK);
  DrawText("Press Enter To Play", 165, 300, 40, BLACK);
}

void playerHUD() {
  AssetSystem::instance().drawTexture(uiAssets[1], 0, 0);
  DrawText(TextFormat("Enemies remaining: %d", EnemyManager::enemyCount), 20,
           20, 20, BLACK);
  DrawText(TextFormat("Ammo: %d", PlayerState::playerAmmo), 20, 50, 20, BLACK);
  DrawText(TextFormat("Health: %d", PlayerState::health), 20, 80, 20, BLACK);
  DrawText(TextFormat("Score: %d", PlayerState::score), 20, 110, 20, BLACK);
};

PauseMenuOpts pauseMenu() {
  AssetSystem::instance().drawTexture(uiAssets[2], 0, 0);
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
  AssetSystem::instance().drawTexture(uiAssets[3], 0, 0);
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
