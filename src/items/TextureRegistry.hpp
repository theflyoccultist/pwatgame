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
        &a.loadTexture((assetsPath / "items/bobatea.png").string());

    drinkTextures[DrinkType::CALPIS] =
        &a.loadTexture((assetsPath / "items/calpis.png").string());

    drinkTextures[DrinkType::CHAMPAGNE] =
        &a.loadTexture((assetsPath / "items/champagne.png").string());

    drinkTextures[DrinkType::COFFEEMACHINE] =
        &a.loadTexture((assetsPath / "items/coffeemachine.png").string());

    drinkTextures[DrinkType::COFFEEMUG] =
        &a.loadTexture((assetsPath / "items/coffeemug.png").string());

    drinkTextures[DrinkType::COFFEEPAPER] =
        &a.loadTexture((assetsPath / "items/coffeepaper.png").string());

    drinkTextures[DrinkType::GINGERALE] =
        &a.loadTexture((assetsPath / "items/gingerale.png").string());

    drinkTextures[DrinkType::ICECOFFEE] =
        &a.loadTexture((assetsPath / "items/icecoffee.png").string());

    drinkTextures[DrinkType::MONSTER] =
        &a.loadTexture((assetsPath / "items/monster.png").string());

    drinkTextures[DrinkType::SOJU] =
        &a.loadTexture((assetsPath / "items/soju.png").string());

    drinkTextures[DrinkType::WINE] =
        &a.loadTexture((assetsPath / "items/wine.png").string());

    drinkTextures[DrinkType::ESTROGEN] =
        &a.loadTexture((assetsPath / "items/estrogen.png").string());

    drinkTextures[DrinkType::SKIRT] =
        &a.loadTexture((assetsPath / "items/skirt.png").string());

    drinkTextures[DrinkType::THIGHHIGH] =
        &a.loadTexture((assetsPath / "items/thighhigh.png").string());
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
        &a.loadTexture((assetsPath / "items/blueberry.png").string());

    foodTextures[FoodType::BULDAK] =
        &a.loadTexture((assetsPath / "items/buldak.png").string());

    foodTextures[FoodType::CHERRY] =
        &a.loadTexture((assetsPath / "items/cherry.png").string());

    foodTextures[FoodType::PASTA] =
        &a.loadTexture((assetsPath / "items/pasta.png").string());

    foodTextures[FoodType::PHO] =
        &a.loadTexture((assetsPath / "items/pho.png").string());

    foodTextures[FoodType::PIZZA] =
        &a.loadTexture((assetsPath / "items/pizza.png").string());

    foodTextures[FoodType::SHINRAMYUN] =
        &a.loadTexture((assetsPath / "items/shinramyun.png").string());

    foodTextures[FoodType::STRAWBERRY] =
        &a.loadTexture((assetsPath / "items/strawberry.png").string());

    foodTextures[FoodType::TOAST] =
        &a.loadTexture((assetsPath / "items/toast.png").string());

    foodTextures[FoodType::TOMYUM] =
        &a.loadTexture((assetsPath / "items/tomyum.png").string());

    foodTextures[FoodType::YOPOKKI] =
        &a.loadTexture((assetsPath / "items/yopokki.png").string());
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
        &a.loadTexture((assetsPath / "items/rocket.png").string());

    weaponTextures[WeaponType::GRENADE] =
        &a.loadTexture((assetsPath / "items/grenade.png").string());

    weaponTextures[WeaponType::HELLFIRE] =
        &a.loadTexture((assetsPath / "items/hellfire.png").string());

    weaponTextures[WeaponType::UZI] =
        &a.loadTexture((assetsPath / "items/uzi.png").string());

    weaponTextures[WeaponType::STRAIGHT] =
        &a.loadTexture((assetsPath / "items/straight.png").string());
  }

  static Texture2D *get(WeaponType type) { return weaponTextures[type]; }

private:
  static inline std::unordered_map<WeaponType, Texture2D *> weaponTextures;
};
