#include <cstdint>
#include <memory>
#include <unordered_map>
#include <vector>

#include <sound/SoundEffect.hpp>

class SfxSystem {
public:
  enum class SoundType : uint8_t {
    pwatSteps,
    combatSFX,
    bonusPickup,
    menuSounds
  };

  SfxSystem();

  void playRandSteps();

  void enemyKilled();
  void defaultGun();
  void rocketGun();
  void uziGun();
  void grenade();
  void hellfire();

  void ammoAdded();
  void healthAdded();
  void newWeapon();

  void winBounce();
  void lostBeeps();
  void menuSelect();
  void menuEnter();
  void startLevel();

  void changeSfxVolume(int vol);

private:
  std::unordered_map<SoundType, std::unique_ptr<std::vector<SoundEffect>>>
      fxBank;
};
