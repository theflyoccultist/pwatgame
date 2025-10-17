#include "UILib.hpp"
#include <algorithm>
#include <raylib.h>

void UILib::pauseMenu() {
  DrawRectangle(100, 100, 600, 600, YELLOW);
  DrawText("Game Paused", 150, 140, 20, BLACK);

  static int posPauseMenu = 210;
  if (IsKeyPressed(KEY_DOWN))
    posPauseMenu += 40;
  if (IsKeyPressed(KEY_UP))
    posPauseMenu -= 40;

  posPauseMenu = std::clamp(posPauseMenu, 210, 330);

  DrawRectangle(140, posPauseMenu, 490, 40, GREEN);
  DrawText("Resume", 150, 220, 20, BLACK);
  DrawText("Restart Level", 150, 260, 20, BLACK);
  DrawText("Options", 150, 300, 20, BLACK);
  DrawText("Back to Menu", 150, 340, 20, BLACK);
}
