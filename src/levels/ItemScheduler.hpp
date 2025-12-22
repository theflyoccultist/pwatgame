#pragma once

#include "../World.hpp"
#include "../items/Item_Drink.hpp"
#include "../items/Item_Food.hpp"
#include "../items/Item_Weapon.hpp"
#include "../levels/ScheduleManager.hpp"
#include "../lua/LuaWrapper.hpp"
#include "../lua/TypeFromString.hpp"
#include <concepts>
#include <raylib.h>

template <typename T> inline T extractArgsFor(LuaWrapper &) = delete;

struct DrinkArgs {
  DrinkType type;
  DrinkSpec spec;
};

template <> inline DrinkArgs extractArgsFor<DrinkArgs>(LuaWrapper &lua) {
  DrinkArgs d;
  d.type = TypeFromString::drinkTypeFromString(
      lua.getString("type").value_or("soju"));
  d.spec.hpBonus = lua.getInt("hpBonus").value_or(0);

  return d;
}

struct FoodArgs {
  FoodType type;
  FoodSpec spec;
};

template <> inline FoodArgs extractArgsFor<FoodArgs>(LuaWrapper &lua) {
  FoodArgs f;
  f.type = TypeFromString::foodTypeFromString(
      lua.getString("type").value_or("buldak"));

  f.spec.ammoBonus = lua.getInt("ammoBonus").value_or(0);

  return f;
}

struct WeaponArgs {
  WeaponType type;
  WeaponItemSpec spec;
};

template <> inline WeaponArgs extractArgsFor<WeaponArgs>(LuaWrapper &lua) {
  WeaponArgs w;
  w.type = TypeFromString::weaponTypeFromString(
      lua.getString("type").value_or("rocket"));

  w.spec.ammoBonus = lua.getInt("ammoBonus").value_or(0);

  return w;
}

template <typename T>
concept ItemTypeClass = std::derived_from<T, Item>;

template <typename A>
concept ItemArgs = requires(A a) {
  a.type;
  a.spec;
};

template <ItemTypeClass ItemT> struct ItemArgsFor;

template <> struct ItemArgsFor<ItemDrink> {
  using type = DrinkArgs;
};

template <> struct ItemArgsFor<ItemFood> {
  using type = FoodArgs;
};

template <> struct ItemArgsFor<ItemWeapon> {
  using type = WeaponArgs;
};

class ItemScheduler {
public:
  ItemScheduler(LuaWrapper &lua, World &w, ScheduleManager &sm)
      : lua(lua), world(w), sm(sm) {}

  void loadItemTextures() { world.itemManager.loadItemTextures(); }
  void clearAllItems() { world.itemManager.clearAll(); }

  template <typename T>
    requires ItemTypeClass<T> && ItemArgs<typename ItemArgsFor<T>::type>
  void scheduleFromLuaTable(const char *tablename);
  void scheduleItems(const char *filename);

  void updateItems(const PlayerState &pwatState) {
    world.itemManager.updateAll(pwatState);
    world.itemManager.drawAll();
  }

private:
  LuaWrapper &lua;
  World &world;
  ScheduleManager &sm;
};
