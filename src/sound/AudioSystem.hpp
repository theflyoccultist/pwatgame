#pragma once
#include "GameScore.hpp"
#include "SoundEffect.hpp"
#include <array>
#include <memory>

class AudioSystem {
public:
  static AudioSystem &instance() {
    static AudioSystem instance;
    return instance;
  }

  AudioSystem(const AudioSystem &) = delete;
  AudioSystem &operator=(const AudioSystem &) = delete;

  void playRandSteps();
  void changeSfxVolume(int vol);

  void playTitleTrack();
  void playLevelTrack();

  void pauseMusic();
  void resumeMusic();
  void updateMusic();
  void stopMusic();

  void changeMusicVolume(int vol);

private:
  AudioSystem();
  ~AudioSystem();

  std::unique_ptr<std::array<SoundEffect, 5>> pwatSteps;
  std::unique_ptr<std::array<GameScore, 2>> gameScores;
  int currentTrack = -1;
};
