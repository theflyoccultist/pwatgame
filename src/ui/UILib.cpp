#include "UILib.hpp"
#include <raylib.h>

void UILib::pauseMenu() {
  DrawRectangle(100, 100, 600, 600, YELLOW);
  DrawText("Game Paused", 315, 140, 20, BLACK);
  DrawText("Resume", 315, 220, 20, BLACK);
  DrawText("Restart Level", 315, 260, 20, BLACK);
  DrawText("Options", 315, 300, 20, BLACK);
  DrawText("Back to Menu", 315, 340, 20, BLACK);
}
