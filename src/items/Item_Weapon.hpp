#pragma once

#include "../projectiles/WeaponDatabase.hpp"
#include "../sound/AudioSystem.hpp"
#include "../texture/AssetSystem.hpp"
#include "Item.hpp"
#include "ItemSpec.hpp"
#include "TextureRegistry.hpp"
#include <iostream>
#include <stdexcept>

class ItemWeapon : public Item {
public:
  explicit ItemWeapon(WeaponType weapon)
      : Item(ItemType::Weapon), weaponType(weapon) {}

  void reset(Vector2 pos, const WeaponItemSpec &spec) {
    stats.active = true;
    stats.pos = pos;
    ammoBonus = spec.ammoBonus;
  }

  void applyToPlayer(const PlayerState &player) override {
    ProjectileType newType = weaponToProjectile(weaponType);
    player.upgradeAmmo(newType);
    player.addAmmo(ammoBonus);

    PlayerState::currWeapon = newType;
    PlayerState::currentWeaponSpec = WeaponDataBase::get(newType);

    AudioSystem::instance().sfx->newWeapon();

    std::cout << "Item_Weapon::applyToPlayer() - Picked projectile type: "
              << newType << '\n';

    deactivate();
  }

  void draw() const override {
    if (!isActive())
      return;

    Texture2D *tex = WeaponTextures::get(weaponType);
    if (!tex) {
      std::cerr << "Item_Weapon::draw() - Weapon texture missing\n";
      return;
    }

    AssetSystem::instance().drawTexture(tex, stats.pos.x, stats.pos.y,
                                        stats.size);
  }

private:
  WeaponType weaponType;
  int ammoBonus = 0;

  ProjectileType weaponToProjectile(WeaponType type) {
    switch (type) {
    case WeaponType::ROCKET:
      return ProjectileType::ROCKET;
    case WeaponType::GRENADE:
      return ProjectileType::GRENADE;
    case WeaponType::HELLFIRE:
      return ProjectileType::HELLFIRE;
    case WeaponType::UZI:
      return ProjectileType::UZI;
    case WeaponType::STRAIGHT:
      return ProjectileType::STRAIGHT;

    default:
      throw std::runtime_error("Invalid weaponType");
    }
  }
};
