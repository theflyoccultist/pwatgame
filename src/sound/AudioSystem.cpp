#include "AudioSystem.hpp"
#include "SoundEffect.hpp"
#include <memory>
#include <vector>

AudioSystem::AudioSystem() {
  InitAudioDevice();

  fxBank[SoundType::pwatSteps] = std::make_unique<std::vector<SoundEffect>>(
      std::initializer_list<SoundEffect>{
          SoundEffect("../assets/sfx/pwatwalk1.wav"),
          SoundEffect("../assets/sfx/pwatwalk2.wav"),
          SoundEffect("../assets/sfx/pwatwalk3.wav"),
          SoundEffect("../assets/sfx/pwatwalk4.wav"),
          SoundEffect("../assets/sfx/pwatwalk5.wav"),
      });

  fxBank[SoundType::combatSFX] = std::make_unique<std::vector<SoundEffect>>(
      std::initializer_list<SoundEffect>{
          SoundEffect("../assets/sfx/8bit_explosion.wav"),
          SoundEffect("../assets/sfx/8bit_shoot.wav"),
          SoundEffect("../assets/sfx/longrange.wav"),
      });

  gameScores = std::make_unique<std::array<GameScore, 2>>(
      std::array<GameScore, 2>{GameScore("../assets/music/right_to_rave.ogg"),
                               GameScore("../assets/music/pseudogender.ogg")});
}

AudioSystem::~AudioSystem() { CloseAudioDevice(); }

void AudioSystem::playRandSteps() {
  int index = GetRandomValue(
      0, static_cast<int>(fxBank[SoundType::pwatSteps]->size()) - 1);
  (*fxBank[SoundType::pwatSteps])[index].play();
}

void AudioSystem::enemyKilled() { (*fxBank[SoundType::combatSFX])[0].play(); }
void AudioSystem::defaultGun() { (*fxBank[SoundType::combatSFX])[1].play(); }
void AudioSystem::longrangeGun() { (*fxBank[SoundType::combatSFX])[2].play(); }

void AudioSystem::changeSfxVolume(int vol) {
  float volume = static_cast<float>(vol) / 100;
  for (auto &[type, sounds] : fxBank) {
    for (auto &s : *sounds)
      s.changeSoundVolume(volume);
  }
};

void AudioSystem::playTitleTrack() {
  currentTrack = 0;
  (*gameScores)[0].play();
}

void AudioSystem::playLevelTrack() {
  currentTrack = 1;
  (*gameScores)[1].play();
}

void AudioSystem::pauseMusic() {
  if (currentTrack >= 0)
    (*gameScores)[currentTrack].pause();
}

void AudioSystem::resumeMusic() {
  if (currentTrack >= 0)
    (*gameScores)[currentTrack].resume();
}

void AudioSystem::updateMusic() {
  if (currentTrack >= 0)
    (*gameScores)[currentTrack].update();
}

void AudioSystem::stopMusic() {
  if (currentTrack >= -1)
    (*gameScores)[currentTrack].stop();
}

void AudioSystem::changeMusicVolume(int vol) {
  float volume = static_cast<float>(vol) / 100;
  (*gameScores)[currentTrack].changeScoreVolume(volume);
}
