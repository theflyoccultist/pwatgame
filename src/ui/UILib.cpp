#include "UILib.hpp"
#include "../entities/EnemyManager.hpp"
#include "../texture/AssetSystem.hpp"
#include <algorithm>
#include <array>
#include <format>
#include <raylib.h>
#include <span>
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

template <typename Enum>
Enum runMenuEnum(const char *title, std::span<std::string const> items,
                 int &selectedIndex, int x, int y) {
  AssetSystem::instance().drawTexture(uiAssets[2], 0, 0);
  if (IsKeyPressed(KEY_DOWN))
    selectedIndex++;
  if (IsKeyPressed(KEY_UP))
    selectedIndex--;

  selectedIndex = std::clamp(selectedIndex, 0, (int)items.size() - 1);

  DrawText(title, x, y, 20, BLACK);

  for (int i = 0; i < (int)items.size(); i++) {
    int pos = y + 40 + i * 40;

    if (i == selectedIndex) {
      DrawRectangle(x - 10, pos - 5, 400, 30, PURPLE);
    }

    DrawText(items[i].c_str(), x, pos, 20, BLACK);
  }

  return static_cast<Enum>(selectedIndex);
}

PauseMenuOpts pauseMenu() {
  static int index = 0;
  std::array<std::string, 4> items = {
      "Resume Game",
      "Restart Level",
      "Options",
      "Back to Menu",
  };

  return runMenuEnum<PauseMenuOpts>("Game Paused", items, index, 150, 140);
}

OptionMenuOpts optionsMenu(int musicVol, int sfxVol) {
  static int index = 0;

  std::array<std::string, 2> items = {
      std::format("Music : {}%", musicVol),
      std::format("Sound Effects : {}%", sfxVol),
  };

  return runMenuEnum<OptionMenuOpts>("OPTIONS", items, index, 150, 140);
}

LostMenuOpts losingScreen() {
  static int index = 0;

  std::array<std::string, 2> items = {
      "Restart Level",
      "Back to Menu",
  };

  return runMenuEnum<LostMenuOpts>("Game Over!", items, index, 150, 140);
}

} // namespace UILib
