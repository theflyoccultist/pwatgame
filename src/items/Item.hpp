#pragma once

#include <items/ItemType.hpp>
#include <player/PlayerState.hpp>

#include <raylib.h>

class Item {
protected:
  struct ItemStats {
    Vector2 pos{};
    float size = 50.0f;
    bool active = false;
  };

public:
  Item(ItemType type) : type(type) {}

  ItemType type;
  ItemStats stats;

  virtual ~Item() = default;

  virtual void applyToPlayer(const PlayerState &player) = 0;

  virtual void draw() const = 0;

  bool isActive() const { return stats.active; }
  void deactivate() { stats.active = false; }
};
