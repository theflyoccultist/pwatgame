#include "ItemScheduler.hpp"
#include "../items/ItemsManager.hpp"
#include <algorithm>
#include <expected>
#include <iostream>
#include <utility>

template <typename T>
  requires ItemTypeClass<T> && ItemArgs<typename ItemArgsFor<T>::type>
void ItemScheduler::scheduleFromLuaTable(const char *tablename) {

  using ArgsT = typename ItemArgsFor<T>::type;

  lua.getTable(tablename)
      .and_then([&](void) -> LuaResultT<void> {
        int len = static_cast<int>(lua_rawlen(lua.getState(), -1));

        for (int i = 1; i <= len; i++) {
          lua_rawgeti(lua.getState(), -1, i);

          Vector2 pos{static_cast<float>(lua.getInt("x").value_or(0)),
                      static_cast<float>(lua.getInt("y").value_or(0))};

          double delay = lua.getNumber("delay").value_or(0.0);

          ArgsT args = extractArgsFor<ArgsT>(lua);

          sm.scheduler.schedule(
              delay, [this, pos, args = std::move(args)]() mutable {
                auto &item = world.itemManager.spawnItem<T>(args.type);

                item.reset(pos, args.spec);
              });

          lua_pop(lua.getState(), 1);
        }

        return {};
      })

      .or_else([](LuaError e) {
        std::cerr << "Expected item table: " << e << "\n";
        return std::expected<void, LuaError>();
      });
}

void ItemScheduler::scheduleItems(const char *filename) {
  lua.runFile(filename).or_else([](LuaError e) {
    std::cerr << e << "\n";
    return std::expected<void, LuaError>();
  });

  std::cout << "Item Scheduler: successfully loaded lua script: " << filename
            << "\n";

  scheduleFromLuaTable<ItemDrink>("DrinkSpawns");
  scheduleFromLuaTable<ItemFood>("FoodSpawns");
  scheduleFromLuaTable<ItemWeapon>("WeaponSpawns");

  std::cout << "Item Scheduler - loaded all spawn tables\n";
}
