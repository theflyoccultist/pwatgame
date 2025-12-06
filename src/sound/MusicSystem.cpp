#include "MusicSystem.hpp"

MusicSystem::MusicSystem() {
  gameScores =
      std::make_unique<std::array<GameScore, 6>>(std::array<GameScore, 6>{
          GameScore("../assets/music/right_to_rave.ogg"),
          GameScore("../assets/music/pseudogender.ogg"),
          GameScore("../assets/music/england.ogg"),
          GameScore("../assets/music/boys_in_luv.ogg"),
          GameScore("../assets/music/thoughts.ogg"),
          GameScore("../assets/music/hasuta.ogg"),
      });
}

void MusicSystem::playTitleTrack() {
  currentTrack = 0;
  (*gameScores)[0].play();
}

void MusicSystem::playLevel1Track() {
  currentTrack = 1;
  (*gameScores)[1].play();
}

void MusicSystem::playLevel2Track() {
  currentTrack = 2;
  (*gameScores)[2].play();
}

void MusicSystem::playLevel3Track() {
  currentTrack = 3;
  (*gameScores)[3].play();
}

void MusicSystem::playLevel4Track() {
  currentTrack = 4;
  (*gameScores)[4].play();
}

void MusicSystem::playBossMusic() {
  currentTrack = 5;
  (*gameScores)[5].play();
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
  if (currentTrack >= 0)
    (*gameScores)[currentTrack].stop();
}

void MusicSystem::changeMusicVolume(int vol) {
  float volume = static_cast<float>(vol) / 100;
  (*gameScores)[currentTrack].changeScoreVolume(volume);
}
