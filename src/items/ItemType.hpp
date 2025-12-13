#pragma once

#include <cstdint>

enum class ItemType : uint8_t { Food, Drink, Weapon };

enum class FoodType : uint8_t { BULDAK, PHO, SHINRAMYUN, TOMYUM, YOPOKKI };

enum class DrinkType : uint8_t { MONSTER, SOJU, CALPIS, BOBATEA, ICECOFFEE };

enum class WeaponType : uint8_t { ROCKET, GRENADE, HELLFIRE, UZI, STRAIGHT };
