#include "GameScore.hpp"
#include <array>
#include <memory>

class MusicSystem {
public:
  MusicSystem();
  void playTitleTrack();
  void playLevelTrack();
  void playBossMusic();

  void pauseMusic();
  void resumeMusic();
  void updateMusic();
  void stopMusic();

  void changeMusicVolume(int vol);

private:
  std::unique_ptr<std::array<GameScore, 3>> gameScores;
  int currentTrack = -1;
};
