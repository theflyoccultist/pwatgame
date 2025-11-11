#pragma once
#include "GameScore.hpp"
#include "SoundEffect.hpp"
#include <array>
#include <memory>
#include <unordered_map>
#include <vector>

enum class SoundType { pwatSteps, combatSFX, bonusPickup };

class AudioSystem {
public:
  static AudioSystem &instance() {
    static AudioSystem instance;
    return instance;
  }

  AudioSystem(const AudioSystem &) = delete;
  AudioSystem &operator=(const AudioSystem &) = delete;

  void playRandSteps();
  void defaultGun();
  void rocketGun();

  void ammoAdded();
  void healthAdded();
  void newWeapon();

  void enemyKilled();
  void changeSfxVolume(int vol);

  void playTitleTrack();
  void playLevelTrack();

  void pauseMusic();
  void resumeMusic();
  void updateMusic();
  void stopMusic();

  void changeMusicVolume(int vol);

private:
  AudioSystem();
  ~AudioSystem();

  std::unordered_map<SoundType, std::unique_ptr<std::vector<SoundEffect>>>
      fxBank;

  std::unique_ptr<std::array<GameScore, 2>> gameScores;
  int currentTrack = -1;
};
