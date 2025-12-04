#include "SfxSystem.hpp"

SfxSystem::SfxSystem() {
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
          SoundEffect("../assets/sfx/8bit_rocket.wav"),
          SoundEffect("../assets/sfx/8bit_uzi.wav"),
      });

  fxBank[SoundType::bonusPickup] = std::make_unique<std::vector<SoundEffect>>(
      std::initializer_list<SoundEffect>{
          SoundEffect("../assets/sfx/add_ammo.wav"),
          SoundEffect("../assets/sfx/add_health.wav"),
          SoundEffect("../assets/sfx/upgrade_weapon.wav"),
      });
}

void SfxSystem::playRandSteps() {
  int index = GetRandomValue(
      0, static_cast<int>(fxBank[SoundType::pwatSteps]->size()) - 1);
  (*fxBank[SoundType::pwatSteps])[index].play();
}

void SfxSystem::enemyKilled() { (*fxBank[SoundType::combatSFX])[0].play(); }
void SfxSystem::defaultGun() { (*fxBank[SoundType::combatSFX])[1].play(); }
void SfxSystem::rocketGun() { (*fxBank[SoundType::combatSFX])[2].play(); }
void SfxSystem::uziGun() { (*fxBank[SoundType::combatSFX])[3].play(); }

void SfxSystem::ammoAdded() { (*fxBank[SoundType::bonusPickup])[0].play(); }
void SfxSystem::healthAdded() { (*fxBank[SoundType::bonusPickup])[1].play(); }
void SfxSystem::newWeapon() { (*fxBank[SoundType::bonusPickup])[2].play(); }

void SfxSystem::changeSfxVolume(int vol) {
  float volume = static_cast<float>(vol) / 100;
  for (auto &[type, sounds] : fxBank) {
    for (auto &s : *sounds)
      s.changeSoundVolume(volume);
  }
};
