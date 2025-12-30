#pragma once

#include <cstdint>

enum class ItemType : uint8_t { Drink, Food, Weapon };

enum class DrinkType : uint8_t {
  BOBATEA,
  CALPIS,
  CHAMPAGNE,
  COFFEEMACHINE,
  COFFEEMUG,
  COFFEEPAPER,
  GINGERALE,
  ICECOFFEE,
  MONSTER,
  SOJU,
  WINE,
};

enum class FoodType : uint8_t {
  BLUEBERRY,
  BULDAK,
  CHERRY,
  PASTA,
  PIZZA,
  PHO,
  SHINRAMYUN,
  STRAWBERRY,
  TOAST,
  TOMYUM,
  YOPOKKI,
};

enum class WeaponType : uint8_t { ROCKET, GRENADE, HELLFIRE, UZI, STRAIGHT };
