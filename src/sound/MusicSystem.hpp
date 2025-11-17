#include "GameScore.hpp"
#include <array>
#include <memory>

class MusicSystem {
public:
  MusicSystem();
  void playTitleTrack();
  void playLevelTrack();

  void pauseMusic();
  void resumeMusic();
  void updateMusic();
  void stopMusic();

  void changeMusicVolume(int vol);

private:
  std::unique_ptr<std::array<GameScore, 2>> gameScores;
  int currentTrack = -1;
};
