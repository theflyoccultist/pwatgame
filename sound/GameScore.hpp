#pragma once

#include <raylib.h>
#include <stdexcept>
#include <string>

class GameScore {
public:
  explicit GameScore(const std::string &path) {
    music = LoadMusicStream(path.c_str());
    if (!IsMusicValid(music)) {
      std::runtime_error("Failed to load music: " + path);
    }
  }

  void play() { PlayMusicStream(music); }
  void stop() { StopMusicStream(music); }

private:
  Music music;
};
