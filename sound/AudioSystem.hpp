#pragma once

#include "SoundEffect.hpp"
#include <array>

class AudioSystem {
public:
  void playRandSteps();

private:
  std::array<SoundEffect, 5> pwatSteps = {
      SoundEffect("../assets/sfx/pwatwalk1.wav"),
      SoundEffect("../assets/sfx/pwatwalk2.wav"),
      SoundEffect("../assets/sfx/pwatwalk3.wav"),
      SoundEffect("../assets/sfx/pwatwalk4.wav"),
      SoundEffect("../assets/sfx/pwatwalk5.wav")};
};
