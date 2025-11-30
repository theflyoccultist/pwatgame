#include "ItemScheduler.hpp"
#include "../lua/TypeFromString.hpp"
#include <expected>
#include <iostream>
#include <vector>

void ItemScheduler::scheduleItems(const char *filename) {
  struct spawnItem {
    ItemCategory cat;
    Vector2 pos;
    double delay;
  };

  std::vector<spawnItem> itemSpawnData{};

  lua.runFile(filename).or_else([](LuaError e) {
    std::cerr << e << "\n";
    return std::expected<void, LuaError>();
  });

  lua.getTable("ItemSpawns")
      .and_then([&](void) -> LuaResultT<void> {
        int len = (int)lua_rawlen(lua.getState(), -1);

        for (int i = 1; i <= len; i++) {
          lua_rawgeti(lua.getState(), -1, i);

          spawnItem item;
          item.cat = lua.getString("type")
                         .transform([&](const std::string_view &s) {
                           return TypeFromString::itemTypeFromString(s);
                         })
                         .value_or(ItemCategory::Food);

          item.pos.x = static_cast<float>(lua.getInt("x").value_or(0));
          item.pos.y = static_cast<float>(lua.getInt("y").value_or(0));
          item.delay = lua.getNumber("delay").value_or(0.0);

          itemSpawnData.push_back(item);

          lua_pop(lua.getState(), 1);
        }

        return {};
      })
      .or_else([](LuaError e) {
        std::cerr << "Expected item table: " << e << "\n";
        return std::expected<void, LuaError>();
      });

  for (const auto &spawn : itemSpawnData) {
    sm.scheduler.schedule(spawn.delay, [c = spawn.cat, p = spawn.pos, this] {
      world.itemManager.populateItems(c, p);
    });
  }
}
