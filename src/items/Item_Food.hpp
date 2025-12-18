#pragma once

#include "../sound/AudioSystem.hpp"
#include "../texture/AssetSystem.hpp"
#include "Item.hpp"
#include "ItemSpec.hpp"
#include "TextureRegistry.hpp"
#include <iostream>

class ItemFood : public Item {
public:
  explicit ItemFood(FoodType t) : Item(ItemType::Food), type(t) {}

  void reset(Vector2 pos, const FoodSpec &spec) {
    stats.active = true;
    stats.pos = pos;
    ammoBonus = spec.ammoBonus;
  }

  void applyToPlayer(const PlayerState &player) override {
    player.addAmmo(ammoBonus);

    AudioSystem::instance().sfx->ammoAdded();

    deactivate();
  }

  void draw() const override {
    if (!isActive())
      return;

    Texture2D *tex = FoodTextures::get(type);
    if (!tex) {
      std::cerr << "Food Item texture missing\n";
      return;
    }

    AssetSystem::instance().drawTexture(tex, (int)stats.pos.x,
                                        (int)stats.pos.y);
  }

  FoodType getType() const { return type; }

private:
  FoodType type;
  int ammoBonus = 0;
};
