#pragma once

#include <memory>
#include <sound/MusicSystem.hpp>
#include <sound/SfxSystem.hpp>

class AudioSystem {
public:
  static AudioSystem &instance() {
    static AudioSystem instance;
    return instance;
  }

  std::unique_ptr<SfxSystem> sfx;
  std::unique_ptr<MusicSystem> music;

  AudioSystem(const AudioSystem &) = delete;
  AudioSystem &operator=(const AudioSystem &) = delete;

private:
  AudioSystem() {
    InitAudioDevice();
    sfx = std::make_unique<SfxSystem>();
    music = std::make_unique<MusicSystem>();
  }

  ~AudioSystem() {
    music.reset();
    sfx.reset();
    CloseAudioDevice();
  }
};
