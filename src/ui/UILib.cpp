#include "UILib.hpp"
#include <algorithm>
#include <array>
#include <raylib.h>

UILib::PauseMenuOpts UILib::pauseMenu() {
  DrawRectangle(100, 100, 600, 600, YELLOW);
  DrawText("Game Paused", 150, 140, 20, BLACK);

  static int selectedIndex = 0;

  if (IsKeyPressed(KEY_DOWN))
    selectedIndex++;
  if (IsKeyPressed(KEY_UP))
    selectedIndex--;

  selectedIndex = std::clamp(selectedIndex, 0, (int)PauseMenuOpts::Count - 1);

  const int baseY = 210;
  const int spacing = 40;
  int posPauseMenu = baseY + selectedIndex * spacing;
  DrawRectangle(140, posPauseMenu, 490, 40, GREEN);

  std::array<const char *, 4> menuItems = {"Resume Game", "Restart Level",
                                           "Options", "Back to Menu"};

  int menuPosition = baseY + 10;
  for (auto text : menuItems) {
    DrawText(text, 150, menuPosition, 20, BLACK);
    menuPosition += spacing;
  }

  return static_cast<PauseMenuOpts>(selectedIndex);
}

void UILib::optionsMenu() {
  DrawText("OPTIONS", 275, 20, 20, DARKPURPLE);
  DrawText("Hello", 275, 400, 60, BLACK);
}

void UILib::mainMenu() {
  DrawText("PwatPwat - The Game", 275, 20, 20, DARKPURPLE);
  DrawText("PLAY", 275, 400, 60, BLACK);
}
