#pragma once

#include <cstdint>

enum class ItemType : uint8_t { Drink, Food, Weapon };

enum class DrinkType : uint8_t {
  MONSTER,
  SOJU,
  CALPIS,
  BOBATEA,
  ICECOFFEE,
  CHAMPAGNE,
  GINGERALE,
  WINE
};

enum class FoodType : uint8_t {
  BULDAK,
  PHO,
  SHINRAMYUN,
  TOMYUM,
  YOPOKKI,
  BLUEBERRY,
  CHERRY,
  STRAWBERRY
};

enum class WeaponType : uint8_t { ROCKET, GRENADE, HELLFIRE, UZI, STRAIGHT };
