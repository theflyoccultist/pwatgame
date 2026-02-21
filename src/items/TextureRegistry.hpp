#pragma once

#include <Paths/Paths.hpp>
#include <items/ItemType.hpp>
#include <raylib.h>
#include <texture/AssetSystem.hpp>
#include <unordered_map>

class DrinkTextures {
public:
  DrinkTextures() = default;

  void loadTextures() {
    auto &a = AssetSystem::instance();
    const fs::path assetsPath = Paths::getAssetsPath();

    drinkTextures[DrinkType::BOBATEA] =
        &a.loadTexture(assetsPath / "items/bobatea.png");

    drinkTextures[DrinkType::CALPIS] =
        &a.loadTexture(assetsPath / "items/calpis.png");

    drinkTextures[DrinkType::CHAMPAGNE] =
        &a.loadTexture(assetsPath / "items/champagne.png");

    drinkTextures[DrinkType::COFFEEMACHINE] =
        &a.loadTexture(assetsPath / "items/coffeemachine.png");

    drinkTextures[DrinkType::COFFEEMUG] =
        &a.loadTexture(assetsPath / "items/coffeemug.png");

    drinkTextures[DrinkType::COFFEEPAPER] =
        &a.loadTexture(assetsPath / "items/coffeepaper.png");

    drinkTextures[DrinkType::GINGERALE] =
        &a.loadTexture(assetsPath / "items/gingerale.png");

    drinkTextures[DrinkType::ICECOFFEE] =
        &a.loadTexture(assetsPath / "items/icecoffee.png");

    drinkTextures[DrinkType::MONSTER] =
        &a.loadTexture(assetsPath / "items/monster.png");

    drinkTextures[DrinkType::SOJU] =
        &a.loadTexture(assetsPath / "items/soju.png");

    drinkTextures[DrinkType::WINE] =
        &a.loadTexture(assetsPath / "items/wine.png");

    drinkTextures[DrinkType::ESTROGEN] =
        &a.loadTexture(assetsPath / "items/estrogen.png");

    drinkTextures[DrinkType::SKIRT] =
        &a.loadTexture(assetsPath / "items/skirt.png");

    drinkTextures[DrinkType::THIGHHIGH] =
        &a.loadTexture(assetsPath / "items/thighhigh.png");
  }

  static Texture2D *get(DrinkType type) { return drinkTextures[type]; }

private:
  static inline std::unordered_map<DrinkType, Texture2D *> drinkTextures;
};

class FoodTextures {
public:
  FoodTextures() = default;

  void loadTextures() {
    auto &a = AssetSystem::instance();
    const fs::path assetsPath = Paths::getAssetsPath();

    foodTextures[FoodType::BLUEBERRY] =
        &a.loadTexture(assetsPath / "items/blueberry.png");

    foodTextures[FoodType::BULDAK] =
        &a.loadTexture(assetsPath / "items/buldak.png");

    foodTextures[FoodType::CHERRY] =
        &a.loadTexture(assetsPath / "items/cherry.png");

    foodTextures[FoodType::PASTA] =
        &a.loadTexture(assetsPath / "items/pasta.png");

    foodTextures[FoodType::PHO] = &a.loadTexture(assetsPath / "items/pho.png");

    foodTextures[FoodType::PIZZA] =
        &a.loadTexture(assetsPath / "items/pizza.png");

    foodTextures[FoodType::SHINRAMYUN] =
        &a.loadTexture(assetsPath / "items/shinramyun.png");

    foodTextures[FoodType::STRAWBERRY] =
        &a.loadTexture(assetsPath / "items/strawberry.png");

    foodTextures[FoodType::TOAST] =
        &a.loadTexture(assetsPath / "items/toast.png");

    foodTextures[FoodType::TOMYUM] =
        &a.loadTexture(assetsPath / "items/tomyum.png");

    foodTextures[FoodType::YOPOKKI] =
        &a.loadTexture(assetsPath / "items/yopokki.png");
  }

  static Texture2D *get(FoodType type) { return foodTextures[type]; }

private:
  static inline std::unordered_map<FoodType, Texture2D *> foodTextures;
};

class WeaponTextures {

public:
  WeaponTextures() = default;

  void loadTextures() {
    auto &a = AssetSystem::instance();
    const fs::path assetsPath = Paths::getAssetsPath();

    weaponTextures[WeaponType::ROCKET] =
        &a.loadTexture(assetsPath / "items/rocket.png");

    weaponTextures[WeaponType::GRENADE] =
        &a.loadTexture(assetsPath / "items/grenade.png");

    weaponTextures[WeaponType::HELLFIRE] =
        &a.loadTexture(assetsPath / "items/hellfire.png");

    weaponTextures[WeaponType::UZI] =
        &a.loadTexture(assetsPath / "items/uzi.png");

    weaponTextures[WeaponType::STRAIGHT] =
        &a.loadTexture(assetsPath / "items/straight.png");
  }

  static Texture2D *get(WeaponType type) { return weaponTextures[type]; }

private:
  static inline std::unordered_map<WeaponType, Texture2D *> weaponTextures;
};
