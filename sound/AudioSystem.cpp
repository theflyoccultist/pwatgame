#include "AudioSystem.hpp"
#include <cstddef>

SoundEffect &AudioSystem::getStepSound(std::size_t i) {
  return (*pwatSteps)[i];
}

void AudioSystem::playRandSteps() {
  if (!pwatSteps)
    return;

  int index = GetRandomValue(0, static_cast<int>(pwatSteps->size()) - 1);
  getStepSound(index).play();
}
