#include "AudioSystem.hpp"

AudioSystem::AudioSystem() {
  InitAudioDevice();
  pwatSteps = std::make_unique<std::array<SoundEffect, 5>>(
      std::array<SoundEffect, 5>{SoundEffect("../assets/sfx/pwatwalk1.wav"),
                                 SoundEffect("../assets/sfx/pwatwalk2.wav"),
                                 SoundEffect("../assets/sfx/pwatwalk3.wav"),
                                 SoundEffect("../assets/sfx/pwatwalk4.wav"),
                                 SoundEffect("../assets/sfx/pwatwalk5.wav")});

  gameScores = std::make_unique<std::array<GameScore, 2>>(
      std::array<GameScore, 2>{GameScore("../assets/music/right_to_rave.ogg"),
                               GameScore("../assets/music/pseudogender.ogg")});
}

AudioSystem::~AudioSystem() { CloseAudioDevice(); }

void AudioSystem::playRandSteps() {
  int index = GetRandomValue(0, static_cast<int>(pwatSteps->size()) - 1);
  (*pwatSteps)[index].play();
}

void AudioSystem::playTitleTrack() {
  currentTrack = 0;
  (*gameScores)[0].play();
}

void AudioSystem::playLevelTrack() {
  currentTrack = 1;
  (*gameScores)[1].play();
}

void AudioSystem::pauseMusic() {
  if (currentTrack >= 0)
    (*gameScores)[currentTrack].pause();
}

void AudioSystem::resumeMusic() {
  if (currentTrack >= 0)
    (*gameScores)[currentTrack].resume();
}

void AudioSystem::updateMusic() {
  if (currentTrack >= 0)
    (*gameScores)[currentTrack].update();
}

void AudioSystem::stopMusic() {
  if (currentTrack >= -1)
    (*gameScores)[currentTrack].stop();
}

void AudioSystem::changeMusicVolume(int vol) {
  vol /= 100.0;
  (*gameScores)[currentTrack].changeScoreVolume(vol);
}
