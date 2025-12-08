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

enum class AssetType : uint8_t { Background, PwatMenu, PwatSprite, PwatLevels };

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

  assetBank[AssetType::PwatLevels] = {
      "../assets/ui/pwatlevel1.png",
      "../assets/ui/pwatlevel2.png",
      "../assets/ui/pwatlevel3.png",
      "../assets/ui/pwatlevel4.png",
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

  for (auto &lvl : assetBank[AssetType::PwatLevels]) {
    uiAssets[AssetType::PwatLevels].push_back(
        &asset.loadTexture(lvl, 150, 150));
  }
}

MainMenuOpts mainMenu() {
  AssetSystem::instance().drawTexture(uiAssets[AssetType::Background][0], 0, 0);
  AssetSystem::instance().drawTexture(uiAssets[AssetType::PwatMenu][0], 225,
                                      225);
  DrawText("PwatPwat - The Game", 165, 80, 40, BLACK);

  static int selectedIndex = 0;

  if (IsKeyPressed(KEY_DOWN))
    selectedIndex++;
  if (IsKeyPressed(KEY_UP))
    selectedIndex--;

  selectedIndex = std::clamp(selectedIndex, 0, (int)MainMenuOpts::Count - 1);

  int posMainMenu = 540 + selectedIndex * 60;
  DrawRectangle(180, posMainMenu, 400, 50, GREEN);

  DrawText("Play Game", 305, 550, 30, BLACK);
  DrawText("Select Level", 285, 610, 30, BLACK);

  return static_cast<MainMenuOpts>(selectedIndex);
}

LevelOpts levelSelection() {
  auto &asset = AssetSystem::instance();
  asset.drawTexture(uiAssets[AssetType::Background][0], 0, 0);
  DrawText("Level Selection", 235, 80, 40, BLACK);

  static int selectedIndex = 0;
  static int xPos = 150;
  static int yPos = 155;

  if (IsKeyPressed(KEY_RIGHT)) {
    selectedIndex++;
    xPos += 250;
  }
  if (IsKeyPressed(KEY_LEFT)) {
    selectedIndex--;
    xPos -= 250;
  }
  if (IsKeyPressed(KEY_DOWN)) {
    selectedIndex += 2;
    yPos += 270;
  }
  if (IsKeyPressed(KEY_UP)) {
    selectedIndex -= 2;
    yPos -= 270;
  }

  selectedIndex = std::clamp(selectedIndex, 0, (int)LevelOpts::Count - 1);
  xPos = std::clamp(xPos, 150, 400);
  yPos = std::clamp(yPos, 155, 425);

  DrawRectangle(xPos, yPos, 200, 200, GREEN);
  DrawText("Level 1", 210, 365, 20, BLACK);
  asset.drawTexture(uiAssets[AssetType::PwatLevels][0], 175, 180);

  DrawText("Level 2", 460, 365, 20, BLACK);
  asset.drawTexture(uiAssets[AssetType::PwatLevels][1], 425, 180);

  DrawText("Level 3", 210, 635, 20, BLACK);
  asset.drawTexture(uiAssets[AssetType::PwatLevels][2], 175, 450);

  DrawText("Level 4", 460, 635, 20, BLACK);
  asset.drawTexture(uiAssets[AssetType::PwatLevels][3], 425, 450);

  DrawText("Backspace : Back To Menu", 170, 700, 30, BLACK);

  return static_cast<LevelOpts>(selectedIndex);
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
