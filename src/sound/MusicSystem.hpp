#include "GameScore.hpp"
#include <array>
#include <memory>

class MusicSystem {
public:
  MusicSystem();
  void playTitleTrack();
  void playLevel1Track();
  void playLevel2Track();
  void playLevel3Track();
  void playLevel4Track();
  void playBossMusic();

  void pauseMusic();
  void resumeMusic();
  void updateMusic();
  void stopMusic();

  void changeMusicVolume(int vol);

private:
  std::unique_ptr<std::array<GameScore, 6>> gameScores;
  int currentTrack = -1;
};
