#pragma once
#include "GameScore.hpp"
#include "SoundEffect.hpp"
#include <array>
#include <memory>

class AudioSystem {
public:
  AudioSystem() {
    InitAudioDevice();
    loadSounds();
    loadMusic();
  }

  ~AudioSystem() {
    pwatSteps.reset();
    gameScores.reset();
    CloseAudioDevice();
  }

  AudioSystem(const AudioSystem &) = delete;
  AudioSystem &operator=(const AudioSystem &) = delete;

  void playRandSteps();

private:
  SoundEffect &getStepSound(std::size_t i);

  void loadSounds() {
    pwatSteps = std::make_unique<std::array<SoundEffect, 5>>(
        std::array<SoundEffect, 5>{SoundEffect("../assets/sfx/pwatwalk1.wav"),
                                   SoundEffect("../assets/sfx/pwatwalk2.wav"),
                                   SoundEffect("../assets/sfx/pwatwalk3.wav"),
                                   SoundEffect("../assets/sfx/pwatwalk4.wav"),
                                   SoundEffect("../assets/sfx/pwatwalk5.wav")});
  }

  void loadMusic() {
    gameScores =
        std::make_unique<std::array<GameScore, 2>>(std::array<GameScore, 2>{
            GameScore("../assets/music/right_to_rave.ogg"),
            GameScore("../assets/music/pseudogender.ogg")});
  }

  std::unique_ptr<std::array<SoundEffect, 5>> pwatSteps;
  std::unique_ptr<std::array<GameScore, 2>> gameScores;
};
