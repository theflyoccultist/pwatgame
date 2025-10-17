#include "UILib.hpp"
#include <raylib.h>

void UILib::pauseMenu() {
  DrawText("Pause Menu", 255, 150, 20, PURPLE);
  DrawRectangle(200, 300, 400, 600, LIGHTGRAY);
}
