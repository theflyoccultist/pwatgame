#include "MusicSystem.hpp"

MusicSystem::MusicSystem() {
  gameScores =
      std::make_unique<std::array<GameScore, 2>>(std::array<GameScore, 2>{
          GameScore("../assets/music/right_to_rave.ogg"),
          GameScore("../assets/music/pseudogender.ogg"),
      });
}

void MusicSystem::playTitleTrack() {
  currentTrack = 0;
  (*gameScores)[0].play();
}

void MusicSystem::playLevelTrack() {
  currentTrack = 1;
  (*gameScores)[1].play();
}

void MusicSystem::pauseMusic() {
  if (currentTrack >= 0)
    (*gameScores)[currentTrack].pause();
}

void MusicSystem::resumeMusic() {
  if (currentTrack >= 0)
    (*gameScores)[currentTrack].resume();
}

void MusicSystem::updateMusic() {
  if (currentTrack >= 0)
    (*gameScores)[currentTrack].update();
}

void MusicSystem::stopMusic() {
  if (currentTrack >= -1)
    (*gameScores)[currentTrack].stop();
}

void MusicSystem::changeMusicVolume(int vol) {
  float volume = static_cast<float>(vol) / 100;
  (*gameScores)[currentTrack].changeScoreVolume(volume);
}
