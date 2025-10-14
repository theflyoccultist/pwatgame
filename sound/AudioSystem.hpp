#pragma once
#include "SoundEffect.hpp"
#include <array>
#include <memory>

class AudioSystem {
public:
  AudioSystem() {
    InitAudioDevice();
    loadSounds();
  }

  ~AudioSystem() {
    pwatSteps.reset();
    CloseAudioDevice();
  }

  AudioSystem(const AudioSystem &) = delete;
  AudioSystem &operator=(const AudioSystem &) = delete;

  void playRandSteps();

private:
  void loadSounds() {
    pwatSteps = std::make_unique<std::array<SoundEffect, 5>>(
        std::array<SoundEffect, 5>{SoundEffect("../assets/sfx/pwatwalk1.wav"),
                                   SoundEffect("../assets/sfx/pwatwalk2.wav"),
                                   SoundEffect("../assets/sfx/pwatwalk3.wav"),
                                   SoundEffect("../assets/sfx/pwatwalk4.wav"),
                                   SoundEffect("../assets/sfx/pwatwalk5.wav")});
  }

  std::unique_ptr<std::array<SoundEffect, 5>> pwatSteps;
};
