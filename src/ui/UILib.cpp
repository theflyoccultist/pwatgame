#include "UILib.hpp"
#include "../player/Player.hpp"
#include "../texture/AssetSystem.hpp"
#include <algorithm>
#include <array>
#include <cstdint>
#include <format>
#include <raylib.h>
#include <span>
#include <string>
#include <unordered_map>
#include <vector>

namespace UILib {

enum class AssetType : uint8_t { Background, PwatMenu, PwatSprite };

std::unordered_map<AssetType, std::vector<std::string>> assetBank;
std::unordered_map<AssetType, std::vector<Texture2D *>> uiAssets;

void loadUIAssets() {
  assetBank[AssetType::Background] = {
      "../assets/ui/bkg1.png", "../assets/ui/bkg2.png", "../assets/ui/bkg3.png",
      "../assets/ui/bkg4.png", "../assets/ui/bkg5.png",
  };

  assetBank[AssetType::PwatMenu] = {
      "../assets/ui/pwat_menu.png",
      "../assets/ui/pwat_pause.png",
      "../assets/ui/pwat_options.png",
  };

  assetBank[AssetType::PwatSprite] = {
      "../assets/ui/pwat_lost.png",
      "../assets/ui/pwat_win.png",
  };

  auto &asset = AssetSystem::instance();

  for (auto &bkg : assetBank[AssetType::Background]) {
    uiAssets[AssetType::Background].push_back(
        &asset.loadTexture(bkg, 800, 800));
  }

  for (auto &mnu : assetBank[AssetType::PwatMenu]) {
    uiAssets[AssetType::PwatMenu].push_back(&asset.loadTexture(mnu, 300, 300));
  }

  for (auto &spr : assetBank[AssetType::PwatSprite]) {
    uiAssets[AssetType::PwatSprite].push_back(&asset.loadSprite(spr));
  }
}

void mainMenu() {
  AssetSystem::instance().drawTexture(uiAssets[AssetType::Background][0], 0, 0);
  AssetSystem::instance().drawTexture(uiAssets[AssetType::PwatMenu][0], 225,
                                      400);
  DrawText("PwatPwat - The Game", 275, 20, 20, BLACK);
  DrawText("Press Enter To Play", 165, 300, 40, BLACK);
}

void playerHUD(int currentLevel) {
  AssetSystem::instance().drawTexture(
      uiAssets[AssetType::Background][currentLevel], 0, 0);
  DrawText(TextFormat("Current Level: %d", currentLevel), 20, 20, 20, BLACK);
  DrawText(TextFormat("Ammo: %d", PlayerState::playerAmmo), 20, 50, 20, BLACK);
  DrawText(TextFormat("Health: %d", PlayerState::health), 20, 80, 20, BLACK);
  DrawText(TextFormat("Score: %d", PlayerState::score), 20, 110, 20, BLACK);
};

template <typename Enum>
Enum runMenuEnum(const char *title, std::span<std::string const> items,
                 int &selectedIndex, int x, int y) {
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
  AssetSystem::instance().drawTexture(uiAssets[AssetType::Background][2], 0, 0);
  static int index = 0;
  std::array<std::string, 4> items = {
      "Resume Game",
      "Restart Level",
      "Options",
      "Back to Menu",
  };

  AssetSystem::instance().drawTexture(uiAssets[AssetType::PwatMenu][1], 225,
                                      400);

  return runMenuEnum<PauseMenuOpts>("Game Paused", items, index, 150, 140);
}

OptionMenuOpts optionsMenu(int musicVol, int sfxVol) {
  AssetSystem::instance().drawTexture(uiAssets[AssetType::Background][3], 0, 0);
  static int index = 0;

  std::array<std::string, 2> items = {
      std::format("Music : {}%", musicVol),
      std::format("Sound Effects : {}%", sfxVol),
  };

  AssetSystem::instance().drawTexture(uiAssets[AssetType::PwatMenu][2], 225,
                                      400);
  return runMenuEnum<OptionMenuOpts>("OPTIONS", items, index, 150, 140);
}

LostMenuOpts losingScreen() {
  AssetSystem::instance().drawTexture(uiAssets[AssetType::Background][4], 0, 0);
  static int index = 0;

  DrawText(TextFormat("Total Score : %d", PlayerState::score), 150, 300, 20,
           PURPLE);

  std::array<std::string, 2> items = {
      "Restart Level",
      "Back to Menu",
  };

  AssetSystem::instance().drawSprite(*uiAssets[AssetType::PwatSprite][0],
                                     {350.0f, 400.0f}, 14);
  return runMenuEnum<LostMenuOpts>("Game Over!", items, index, 150, 140);
}

WinMenuOpts winningMenu(int currentLevel) {
  AssetSystem::instance().drawTexture(uiAssets[AssetType::Background][4], 0, 0);
  static int index = 0;
  DrawText(TextFormat("Total Score : %d", PlayerState::score), 150, 300, 20,
           PURPLE);

  std::array<std::string, 3> items = {
      "Next Level",
      "Restart Level",
      "Back to Menu",
  };

  if (currentLevel == 4)
    items[0] = "Show Credits";

  AssetSystem::instance().drawSprite(*uiAssets[AssetType::PwatSprite][1],
                                     {350.0f, 400.0f}, 14);

  return runMenuEnum<WinMenuOpts>("You WON!!", items, index, 150, 140);
}

void CreditsMenu() { DrawText("Rin Delahaije: Everyhing", 225, 225, 50, BLUE); }

} // namespace UILib
