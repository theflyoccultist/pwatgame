#include <sound/GameScore.hpp>

#include <array>
#include <memory>

class MusicSystem {
public:
  MusicSystem();

  MusicSystem(const MusicSystem &) = delete;
  MusicSystem &operator=(const MusicSystem &) = delete;

  void playTitleTrack();
  void playLevel1Track();
  void playLevel1BossMusic();
  void playLevel2Track();
  void playLevel2BossMusic();
  void playLevel3Track();
  void playLevel3BossMusic();
  void playLevel4Track();
  void playLevel4BossMusic();

  void pauseMusic();
  void resumeMusic();
  void updateMusic();
  void stopMusic();

  void changeMusicVolume(int vol);

private:
  std::unique_ptr<std::array<GameScore, 9>> gameScores;
  int currentTrack = -1;
};
