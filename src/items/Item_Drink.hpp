#pragma once

#include "../texture/AssetSystem.hpp"
#include "Item.hpp"
#include "ItemSpec.hpp"
#include "TextureRegistry.hpp"
#include <iostream>

class ItemDrink : public Item {
public:
  explicit ItemDrink(DrinkType t) : Item(ItemType::Drink), type(t) {}

  void reset(Vector2 pos, const DrinkSpec &spec) {
    stats.active = true;
    stats.pos = pos;
    hpBonus = spec.hpBonus;
  }

  void applyToPlayer(const PlayerState &player) override {
    player.addHealth(hpBonus);

    AudioSystem::instance().sfx->healthAdded();

    deactivate();
  }

  void draw() const override {
    if (!isActive())
      return;

    Texture2D *tex = DrinkTextures::get(type);
    if (!tex) {
      std::cerr << "Drink Item texture missing\n";
      return;
    }

    AssetSystem::instance().drawTexture(tex, (int)stats.pos.x,
                                        (int)stats.pos.y);
  }

  DrinkType getType() const { return type; }

private:
  DrinkType type;
  int hpBonus = 0;
};
