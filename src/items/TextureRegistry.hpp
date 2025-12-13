#pragma once

#include "../texture/AssetSystem.hpp"
#include "ItemType.hpp"
#include <raylib.h>
#include <unordered_map>

class DrinkTextures {
public:
  static void loadTextures() {
    auto &a = AssetSystem::instance();

    drinkTextures[DrinkType::MONSTER] =
        &a.loadTexture("../assets/items/monster.png", 50, 50);

    drinkTextures[DrinkType::SOJU] =
        &a.loadTexture("../assets/items/soju.png", 50, 50);

    drinkTextures[DrinkType::CALPIS] =
        &a.loadTexture("../assets/items/calpis.png", 50, 50);

    drinkTextures[DrinkType::BOBATEA] =
        &a.loadTexture("../assets/items/bobatea.png", 50, 50);

    drinkTextures[DrinkType::ICECOFFEE] =
        &a.loadTexture("../assets/items/icecoffee.png", 50, 50);
  }

  static Texture2D *get(DrinkType type) { return drinkTextures[type]; }

private:
  static inline std::unordered_map<DrinkType, Texture2D *> drinkTextures;
};

class FoodTextures {
public:
  static void loadTextures() {
    auto &a = AssetSystem::instance();

    foodTextures[FoodType::BULDAK] =
        &a.loadTexture("../assets/items/buldak.png", 50, 50);

    foodTextures[FoodType::PHO] =
        &a.loadTexture("../assets/items/pho.png", 50, 50);

    foodTextures[FoodType::SHINRAMYUN] =
        &a.loadTexture("../assets/items/shinramyun.png", 50, 50);

    foodTextures[FoodType::TOMYUM] =
        &a.loadTexture("../assets/items/tomyum.png", 50, 50);

    foodTextures[FoodType::YOPOKKI] =
        &a.loadTexture("../assets/items/yopokki.png", 50, 50);
  }

  static Texture2D *get(FoodType type) { return foodTextures[type]; }

private:
  static inline std::unordered_map<FoodType, Texture2D *> foodTextures;
};

class WeaponTextures {
public:
  static void loadTextures() {
    auto &a = AssetSystem::instance();

    weaponTextures[WeaponType::ROCKET] =
        &a.loadTexture("../assets/items/rocket.png", 50, 50);

    weaponTextures[WeaponType::GRENADE] =
        &a.loadTexture("../assets/items/grenade.png", 50, 50);

    weaponTextures[WeaponType::HELLFIRE] =
        &a.loadTexture("../assets/items/hellfire.png", 50, 50);

    weaponTextures[WeaponType::UZI] =
        &a.loadTexture("../assets/items/uzi.png", 50, 50);

    weaponTextures[WeaponType::STRAIGHT] =
        &a.loadTexture("../assets/items/straight.png", 50, 50);
  }

  static Texture2D *get(WeaponType type) { return weaponTextures[type]; }

private:
  static inline std::unordered_map<WeaponType, Texture2D *> weaponTextures;
};
