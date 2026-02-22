#include <Paths/Paths.hpp>
#include <player/PlayerState.hpp>
#include <sound/AudioSystem.hpp>
#include <texture/AssetSystem.hpp>
#include <ui/UILib.hpp>

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

enum class AssetType : uint8_t { Background, PwatMenu, WeaponUI, PwatSprite };

std::unordered_map<AssetType, std::vector<std::string>> assetBank;
std::unordered_map<AssetType, std::vector<Texture2D *>> uiAssets;

void loadUIAssets() {
  const fs::path assetsPath = Paths::getAssetsPath();

  assetBank[AssetType::Background] = {
      (assetsPath / "ui/bkg1.png").string(),
      (assetsPath / "ui/bkg2.png").string(),
      (assetsPath / "ui/bkg3.png").string(),
      (assetsPath / "ui/bkg4.png").string(),
      (assetsPath / "ui/bkg5.png").string(),
  };

  assetBank[AssetType::PwatMenu] = {
      (assetsPath / "ui/pwat_menu.png").string(),
      (assetsPath / "ui/pwat_levels.png").string(),
      (assetsPath / "ui/pwat_pause.png").string(),
      (assetsPath / "ui/pwat_options.png").string(),
  };

  assetBank[AssetType::WeaponUI] = {
      (assetsPath / "ui/weapon_grenade.png").string(),
      (assetsPath / "ui/weapon_hellfire.png").string(),
      (assetsPath / "ui/weapon_rocket.png").string(),
      (assetsPath / "ui/weapon_straight.png").string(),
      (assetsPath / "ui/weapon_uzi.png").string(),
      (assetsPath / "ui/weapon_noweapon.png").string(),

  };

  assetBank[AssetType::PwatSprite] = {
      (assetsPath / "ui/pwat_lost.png").string(),
      (assetsPath / "ui/pwat_win.png").string(),
  };

  auto &asset = AssetSystem::instance();

  for (auto &bkg : assetBank[AssetType::Background]) {
    uiAssets[AssetType::Background].push_back(&asset.loadTexture(bkg));
  }

  for (auto &mnu : assetBank[AssetType::PwatMenu]) {
    uiAssets[AssetType::PwatMenu].push_back(&asset.loadTexture(mnu));
  }

  for (auto &wep : assetBank[AssetType::WeaponUI]) {
    uiAssets[AssetType::WeaponUI].push_back(&asset.loadTexture(wep));
  }

  for (auto &spr : assetBank[AssetType::PwatSprite]) {
    uiAssets[AssetType::PwatSprite].push_back(&asset.loadSprite(spr));
  }
}

auto &audio = AudioSystem::instance();

MainMenuOpts mainMenu() {
  AssetSystem::instance().drawTexture(uiAssets[AssetType::Background][0], 0, 0,
                                      800);
  AssetSystem::instance().drawTexture(uiAssets[AssetType::PwatMenu][0], 225,
                                      225, 300);
  DrawText("PwatPwat - The Game", 165, 80, 40, BLACK);

  static int selectedIndex = 0;

  if (IsKeyPressed(KEY_DOWN)) {
    audio.sfx->menuSelect();
    selectedIndex++;
  }

  if (IsKeyPressed(KEY_UP)) {
    audio.sfx->menuSelect();
    selectedIndex--;
  }

  selectedIndex = std::clamp(selectedIndex, 0, (int)MainMenuOpts::Count - 1);

  int posMainMenu = 540 + selectedIndex * 60;
  DrawRectangle(180, posMainMenu, 400, 50, GREEN);

  DrawText("Play Game", 305, 550, 30, BLACK);
  DrawText("Play From Level", 265, 610, 30, BLACK);
  DrawText("Help", 345, 670, 30, BLACK);

  return static_cast<MainMenuOpts>(selectedIndex);
}

void helpHUD() {
  AssetSystem::instance().drawTexture(uiAssets[AssetType::Background][0], 0, 0,
                                      800);

  DrawText("HELP", 355, 80, 40, BLACK);
  DrawText("Press the arrow keys to move across the map!", 115, 180, 20, BLACK);
  DrawText("Press the space key to shoot projectiles towards enemies!", 115,
           230, 20, BLACK);
  DrawText("Pick up food items spread across the map to gain ammo!", 115, 280,
           20, BLACK);
  DrawText("Pick up drink items spread across the map to gain health!", 115,
           330, 20, BLACK);
  DrawText("Pick up weapon items, and discover new ways", 115, 380, 20, BLACK);
  DrawText("to defeat your opponents!", 115, 430, 20, BLACK);
  DrawText("Defeat mini bosses to clear that level!", 115, 480, 20, BLACK);

  DrawText("Press Enter to return to the Main Menu", 155, 680, 25, RED);
}

void levelIntro(int currentLevel) {
  AssetSystem::instance().drawTexture(
      uiAssets[AssetType::Background][currentLevel], 0, 0, 800);
  const char *levelName = "";
  Color introColor = PINK;

  switch (currentLevel) {
  case 1:
    levelName = "The Vile Void";
    introColor = PINK;
    break;
  case 2:
    levelName = "The Isolated Youth";
    introColor = LIME;
    break;
  case 3:
    levelName = "Boys in Love";
    introColor = GOLD;
    break;
  case 4:
    levelName = "Inconsolable Sadness";
    introColor = SKYBLUE;
    break;
  default:
    break;
  }

  DrawRectangle(50, 250, 600, 300, introColor);
  DrawText(TextFormat("Level %d", currentLevel), 100, 300, 40, BLACK);
  DrawText(levelName, 100, 400, 30, BLACK);
  DrawText("Press Enter to continue", 100, 470, 20, BLACK);
}

void playerHUD(int currentLevel) {
  AssetSystem::instance().drawTexture(
      uiAssets[AssetType::Background][currentLevel], 0, 0, 800);

  DrawText(TextFormat("Current Level: %d", currentLevel), 20, 20, 20, BLACK);
  DrawText(TextFormat("Ammo: %d", PlayerState::playerAmmo), 20, 50, 20, BLACK);
  DrawText(TextFormat("Health: %d", PlayerState::playerHealth), 20, 80, 20,
           BLACK);
  DrawText(TextFormat("Score: %d", PlayerState::playerScore), 20, 110, 20,
           BLACK);
};

void weaponHUD(ProjectileType currentProjectile) {
  auto &a = AssetSystem::instance();

  const int x = 680;
  const int y = 20;

  switch (currentProjectile) {
  case ProjectileType::GRENADE:
    a.drawTexture(uiAssets[AssetType::WeaponUI][0], x, y, 100);
    break;
  case ProjectileType::HELLFIRE:
    a.drawTexture(uiAssets[AssetType::WeaponUI][1], x, y, 100);
    break;
  case ProjectileType::ROCKET:
    a.drawTexture(uiAssets[AssetType::WeaponUI][2], x, y, 100);
    break;
  case ProjectileType::STRAIGHT:
    a.drawTexture(uiAssets[AssetType::WeaponUI][3], x, y, 100);
    break;
  case ProjectileType::UZI:
    a.drawTexture(uiAssets[AssetType::WeaponUI][4], x, y, 100);
    break;
  default:
    a.drawTexture(uiAssets[AssetType::WeaponUI][5], x, y, 100);
    break;
  }
};

template <typename Enum>
Enum runMenuEnum(const char *title, std::span<std::string const> items,
                 int &selectedIndex, int x, int y) {
  if (IsKeyPressed(KEY_DOWN)) {
    audio.sfx->menuSelect();
    selectedIndex++;
  }

  if (IsKeyPressed(KEY_UP)) {
    audio.sfx->menuSelect();
    selectedIndex--;
  }

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

LevelOpts levelSelection() {
  AssetSystem::instance().drawTexture(uiAssets[AssetType::Background][0], 0, 0,
                                      800);
  static int index = 0;

  std::array<std::string, 5> levels = {
      "Level 1", "Level 2", "Level 3", "Level 4", "Back to Menu",
  };

  AssetSystem::instance().drawTexture(uiAssets[AssetType::PwatMenu][1], 225,
                                      365, 300);
  return runMenuEnum<LevelOpts>("Level Selection", levels, index, 150, 140);
}

PauseMenuOpts pauseMenu() {
  AssetSystem::instance().drawTexture(uiAssets[AssetType::Background][2], 0, 0,
                                      800);
  static int index = 0;

  std::array<std::string, 4> items = {
      "Resume Game",
      "Restart Level",
      "Options",
      "Back to Menu",
  };

  AssetSystem::instance().drawTexture(uiAssets[AssetType::PwatMenu][2], 225,
                                      400, 300);

  return runMenuEnum<PauseMenuOpts>("Game Paused", items, index, 150, 140);
}

OptionMenuOpts optionsMenu(int musicVol, int sfxVol) {
  AssetSystem::instance().drawTexture(uiAssets[AssetType::Background][3], 0, 0,
                                      800);
  static int index = 0;

  std::array<std::string, 2> items = {
      std::format("Music : {}%", musicVol),
      std::format("Sound Effects : {}%", sfxVol),
  };

  AssetSystem::instance().drawTexture(uiAssets[AssetType::PwatMenu][3], 225,
                                      400, 300);
  return runMenuEnum<OptionMenuOpts>("OPTIONS", items, index, 150, 140);
}

LostMenuOpts losingScreen(GameModes &gameMode) {
  AssetSystem::instance().drawTexture(uiAssets[AssetType::Background][4], 0, 0,
                                      800);
  static int index = 0;

  DrawText(TextFormat("Total Score : %d", PlayerState::playerScore), 150, 300,
           20, PURPLE);

  std::array<std::string, 2> items = {
      "Restart Level",
      "Back to Menu",
  };

  if (gameMode == GameModes::Dealthless)
    items[0] = "Restart Game";

  AssetSystem::instance().drawSprite(*uiAssets[AssetType::PwatSprite][0],
                                     {350.0f, 400.0f}, 14);
  return runMenuEnum<LostMenuOpts>("Game Over!", items, index, 150, 140);
}

WinMenuOpts winningMenu(int currentLevel) {
  AssetSystem::instance().drawTexture(uiAssets[AssetType::Background][4], 0, 0,
                                      800);
  static int index = 0;

  DrawText(TextFormat("Total Score : %d", PlayerState::playerScore), 150, 300,
           20, PURPLE);

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

void CreditsMenu() {
  AssetSystem::instance().drawTexture(uiAssets[AssetType::Background][4], 0, 0,
                                      800);
  DrawText("Credits:", 150, 140, 20, BLUE);

  int posYtxt = 180;
  const std::array<std::string, 6> credits = {
      "Game Engine", "Music", "Scripting", "Direction", "UI", "Marketing",
  };

  for (auto &i : credits) {
    DrawText(std::format("{} : Rin", i).c_str(), 150, posYtxt, 20, BLACK);
    posYtxt += 40;
  }

  AssetSystem::instance().drawSprite(*uiAssets[AssetType::PwatSprite][1],
                                     {450.0f, 250.0f}, 14);

  DrawText("Special Thanks to:", 150, 510, 20, BLUE);
  DrawText("Mom", 150, 550, 20, BLACK);
  DrawText("My cute girlfriend", 150, 590, 20, BLACK);
  DrawText("Raysan5, creator of Raylib", 150, 630, 20, BLACK);
  DrawText("Press Enter to return to the Main Menu", 155, 680, 25, PURPLE);
}

} // namespace UILib
