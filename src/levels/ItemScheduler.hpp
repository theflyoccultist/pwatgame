#pragma once

#include "../World.hpp"
#include "../levels/ScheduleManager.hpp"
#include "../lua/LuaWrapper.hpp"
#include <raylib.h>

class ItemScheduler {
public:
  ItemScheduler(LuaWrapper &lua, World &w, ScheduleManager &sm)
      : lua(lua), world(w), sm(sm) {}

  void clearAllItems() { world.itemManager.clearAll(); }

  void scheduleItems();

  void updateItems(const PlayerState &pwatState) {
    world.itemManager.updateItems(pwatState.position,
                                  (float)pwatState.playerSize);
    world.itemManager.drawItems(ItemCategory::Food);
    world.itemManager.drawItems(ItemCategory::Drink);
    world.itemManager.drawItems(ItemCategory::Weapon);
  }

private:
  LuaWrapper &lua;
  World &world;
  ScheduleManager &sm;
};
