#include "ConfirmQuit.hpp"
#include "../sound/AudioSystem.hpp"

bool paused = false;

void ConfirmQuit::show() {
  if (IsKeyPressed(KEY_P)) {
    paused = !paused;
    paused ? AudioSystem::instance().pauseMusic()
           : AudioSystem::instance().resumeMusic();
    DrawText("Pause Menu", 255, 150, 20, PURPLE);
  }
}
