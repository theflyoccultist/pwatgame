#pragma once

#include <raylib.h>
#include <stdexcept>
#include <string>

class GameScore {
public:
  explicit GameScore(const std::string &path) {
    music = LoadMusicStream(path.c_str());
    if (!IsMusicValid(music)) {
      throw std::runtime_error("Failed to load music: " + path);
    }
  }

  void play() { PlayMusicStream(music); }
  void pause() { PauseMusicStream(music); }
  void resume() { ResumeMusicStream(music); }
  void update() { UpdateMusicStream(music); }
  void stop() { StopMusicStream(music); }

private:
  Music music;
};
