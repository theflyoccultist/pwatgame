#include "AudioSystem.hpp"

void AudioSystem::playRandSteps() {
  if (!pwatSteps)
    return;

  int index = GetRandomValue(0, static_cast<int>(pwatSteps->size()) - 1);
  (*pwatSteps)[index].play();
}
