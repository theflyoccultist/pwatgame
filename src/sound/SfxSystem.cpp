#include <Paths/Paths.hpp>
#include <sound/SfxSystem.hpp>

SfxSystem::SfxSystem() {
  const fs::path assetsPath = Paths::getAssetsPath();

  fxBank[SoundType::pwatSteps] = std::make_unique<std::vector<SoundEffect>>(
      std::initializer_list<SoundEffect>{
          SoundEffect((assetsPath / "sfx/pwatwalk1.wav").string()),
          SoundEffect((assetsPath / "sfx/pwatwalk2.wav").string()),
          SoundEffect((assetsPath / "sfx/pwatwalk3.wav").string()),
          SoundEffect((assetsPath / "sfx/pwatwalk4.wav").string()),
          SoundEffect((assetsPath / "sfx/pwatwalk5.wav").string()),
      });

  fxBank[SoundType::combatSFX] = std::make_unique<std::vector<SoundEffect>>(
      std::initializer_list<SoundEffect>{
          SoundEffect((assetsPath / "sfx/8bit_explosion.wav").string()),
          SoundEffect((assetsPath / "sfx/8bit_shoot.wav").string()),
          SoundEffect((assetsPath / "sfx/8bit_rocket.wav").string()),
          SoundEffect((assetsPath / "sfx/8bit_uzi.wav").string()),
          SoundEffect((assetsPath / "sfx/8bit_grenade.wav").string()),
          SoundEffect((assetsPath / "sfx/8bit_hellfire.wav").string()),
      });

  fxBank[SoundType::bonusPickup] = std::make_unique<std::vector<SoundEffect>>(
      std::initializer_list<SoundEffect>{
          SoundEffect((assetsPath / "sfx/add_ammo.wav").string()),
          SoundEffect((assetsPath / "sfx/add_health.wav").string()),
          SoundEffect((assetsPath / "sfx/upgrade_weapon.wav").string()),
      });

  fxBank[SoundType::menuSounds] = std::make_unique<std::vector<SoundEffect>>(
      std::initializer_list<SoundEffect>{
          SoundEffect((assetsPath / "sfx/boing.wav").string()),
          SoundEffect((assetsPath / "sfx/game_over.wav").string()),
          SoundEffect((assetsPath / "sfx/menu_selection.wav").string()),
          SoundEffect((assetsPath / "sfx/menu_button.wav").string()),
          SoundEffect((assetsPath / "sfx/level_start.wav").string()),
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
void SfxSystem::grenade() { (*fxBank[SoundType::combatSFX])[4].play(); }
void SfxSystem::hellfire() { (*fxBank[SoundType::combatSFX])[5].play(); }

void SfxSystem::ammoAdded() { (*fxBank[SoundType::bonusPickup])[0].play(); }
void SfxSystem::healthAdded() { (*fxBank[SoundType::bonusPickup])[1].play(); }
void SfxSystem::newWeapon() { (*fxBank[SoundType::bonusPickup])[2].play(); }

void SfxSystem::winBounce() { (*fxBank[SoundType::menuSounds])[0].play(); }
void SfxSystem::lostBeeps() { (*fxBank[SoundType::menuSounds])[1].play(); }
void SfxSystem::menuSelect() { (*fxBank[SoundType::menuSounds])[2].play(); }
void SfxSystem::menuEnter() { (*fxBank[SoundType::menuSounds])[3].play(); }
void SfxSystem::startLevel() { (*fxBank[SoundType::menuSounds])[4].play(); }

void SfxSystem::changeSfxVolume(int vol) {
  float volume = static_cast<float>(vol) / 100;
  for (auto &[type, sounds] : fxBank) {
    for (auto &s : *sounds)
      s.changeSoundVolume(volume);
  }
};
