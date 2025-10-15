#include "AudioSystem.hpp"

SoundEffect &AudioSystem::getStepSound(std::size_t i) {
  return (*pwatSteps)[i];
}

void AudioSystem::playRandSteps() {
  if (!pwatSteps)
    return;

  int index = GetRandomValue(0, static_cast<int>(pwatSteps->size()) - 1);
  getStepSound(index).play();
}

GameScore &AudioSystem::gameMusic(std::size_t i) { return (*gameScores)[i]; }

void AudioSystem::updateMusic() {
  for (auto &m : *gameScores) {
    m.update();
  }
}

void AudioSystem::playTitleTrack() { gameMusic(0).play(); }
// GameScore &AudioSystem::playLevelTrack() { return (*gameScores)[1]; }
