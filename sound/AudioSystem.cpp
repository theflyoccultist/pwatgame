#include "AudioSystem.hpp"

void AudioSystem::playRandSteps() {
  pwatSteps[rand() % pwatSteps.size()].play();
}
