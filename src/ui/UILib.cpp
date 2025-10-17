#include "UILib.hpp"
#include <raylib.h>

bool paused = false;

void UILib::pauseMenu() {
  if (IsKeyPressed(KEY_P)) {
    paused = !paused;
  }

  if (paused) {
    DrawText("Pause Menu", 255, 150, 20, PURPLE);
    DrawRectangle(200, 300, 400, 600, LIGHTGRAY);
  }
}
