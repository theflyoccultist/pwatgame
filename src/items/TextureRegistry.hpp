#pragma once

#include "../texture/AssetSystem.hpp"
#include "ItemType.hpp"
#include <raylib.h>
#include <unordered_map>

class DrinkTextures {
public:
  static void loadTextures() {
    auto &a = AssetSystem::instance();

    drinkTextures[DrinkType::BOBATEA] =
        &a.loadTexture("../assets/items/bobatea.png");

    drinkTextures[DrinkType::CALPIS] =
        &a.loadTexture("../assets/items/calpis.png");

    drinkTextures[DrinkType::CHAMPAGNE] =
        &a.loadTexture("../assets/items/champagne.png");

    drinkTextures[DrinkType::COFFEEMACHINE] =
        &a.loadTexture("../assets/items/coffeemachine.png");

    drinkTextures[DrinkType::COFFEEMUG] =
        &a.loadTexture("../assets/items/coffeemug.png");

    drinkTextures[DrinkType::COFFEEPAPER] =
        &a.loadTexture("../assets/items/coffeepaper.png");

    drinkTextures[DrinkType::GINGERALE] =
        &a.loadTexture("../assets/items/gingerale.png");

    drinkTextures[DrinkType::ICECOFFEE] =
        &a.loadTexture("../assets/items/icecoffee.png");

    drinkTextures[DrinkType::MONSTER] =
        &a.loadTexture("../assets/items/monster.png");

    drinkTextures[DrinkType::SOJU] = &a.loadTexture("../assets/items/soju.png");

    drinkTextures[DrinkType::WINE] = &a.loadTexture("../assets/items/wine.png");

    drinkTextures[DrinkType::ESTROGEN] =
        &a.loadTexture("../assets/items/estrogen.png");

    drinkTextures[DrinkType::SKIRT] =
        &a.loadTexture("../assets/items/skirt.png");

    drinkTextures[DrinkType::THIGHHIGH] =
        &a.loadTexture("../assets/items/thighhigh.png");
  }

  static Texture2D *get(DrinkType type) { return drinkTextures[type]; }

private:
  static inline std::unordered_map<DrinkType, Texture2D *> drinkTextures;
};

class FoodTextures {
public:
  static void loadTextures() {
    auto &a = AssetSystem::instance();

    foodTextures[FoodType::BLUEBERRY] =
        &a.loadTexture("../assets/items/blueberry.png");

    foodTextures[FoodType::BULDAK] =
        &a.loadTexture("../assets/items/buldak.png");

    foodTextures[FoodType::CHERRY] =
        &a.loadTexture("../assets/items/cherry.png");

    foodTextures[FoodType::PASTA] = &a.loadTexture("../assets/items/pasta.png");

    foodTextures[FoodType::PHO] = &a.loadTexture("../assets/items/pho.png");

    foodTextures[FoodType::PIZZA] = &a.loadTexture("../assets/items/pizza.png");

    foodTextures[FoodType::SHINRAMYUN] =
        &a.loadTexture("../assets/items/shinramyun.png");

    foodTextures[FoodType::STRAWBERRY] =
        &a.loadTexture("../assets/items/strawberry.png");

    foodTextures[FoodType::TOAST] = &a.loadTexture("../assets/items/toast.png");

    foodTextures[FoodType::TOMYUM] =
        &a.loadTexture("../assets/items/tomyum.png");

    foodTextures[FoodType::YOPOKKI] =
        &a.loadTexture("../assets/items/yopokki.png");
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
        &a.loadTexture("../assets/items/rocket.png");

    weaponTextures[WeaponType::GRENADE] =
        &a.loadTexture("../assets/items/grenade.png");

    weaponTextures[WeaponType::HELLFIRE] =
        &a.loadTexture("../assets/items/hellfire.png");

    weaponTextures[WeaponType::UZI] = &a.loadTexture("../assets/items/uzi.png");

    weaponTextures[WeaponType::STRAIGHT] =
        &a.loadTexture("../assets/items/straight.png");
  }

  static Texture2D *get(WeaponType type) { return weaponTextures[type]; }

private:
  static inline std::unordered_map<WeaponType, Texture2D *> weaponTextures;
};
