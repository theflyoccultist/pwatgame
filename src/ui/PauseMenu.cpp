#include "PauseMenu.hpp"
#include "../sound/AudioSystem.hpp"

bool paused = false;

void PauseMenu::show() {
  if (IsKeyPressed(KEY_P)) {
    paused = !paused;
  }

  if (paused) {
    AudioSystem::instance().pauseMusic();
    DrawText("Pause Menu", 255, 150, 20, PURPLE);
  } else {
    AudioSystem::instance().resumeMusic();
  }
}
