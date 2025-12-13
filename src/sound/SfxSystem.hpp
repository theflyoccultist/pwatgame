#include "SoundEffect.hpp"
#include <cstdint>
#include <memory>
#include <unordered_map>
#include <vector>

class SfxSystem {
public:
  enum class SoundType : uint8_t { pwatSteps, combatSFX, bonusPickup };

  SfxSystem();

  void playRandSteps();
  void defaultGun();
  void rocketGun();
  void uziGun();
  void grenade();
  void hellfire();

  void ammoAdded();
  void healthAdded();
  void newWeapon();

  void enemyKilled();
  void changeSfxVolume(int vol);

private:
  std::unordered_map<SoundType, std::unique_ptr<std::vector<SoundEffect>>>
      fxBank;
};
