#pragma once

#include <items/Item.hpp>
#include <items/ItemSpec.hpp>
#include <items/TextureRegistry.hpp>
#include <sound/AudioSystem.hpp>
#include <texture/AssetSystem.hpp>

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
      std::cerr << "Item_Food::draw() - Food texture missing\n";
      return;
    }

    AssetSystem::instance().drawTexture(tex, stats.pos.x, stats.pos.y,
                                        stats.size);
  }

  FoodType getType() const { return type; }

private:
  FoodType type;
  int ammoBonus = 0;
};
