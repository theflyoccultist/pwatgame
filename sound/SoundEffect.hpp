#pragma once

#include <raylib.h>
#include <stdexcept>
#include <string>

class SoundEffect {
public:
  explicit SoundEffect(const std::string &path) {
    sfx = LoadSound(path.c_str());
    if (!IsSoundValid(sfx)) {
      throw std::runtime_error("Failed to load sfx: " + path);
    }
  }

  void play() { PlaySound(sfx); }
  void stop() { StopSound(sfx); }

private:
  Sound sfx;
};
