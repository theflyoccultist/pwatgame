#pragma once

#include "ItemSpec.hpp"
#include "ItemType.hpp"
#include <unordered_map>

class ItemDatabase {
public:
  void loadFood();
  void loadDrink();

  static const FoodSpec &get(FoodType t);
  static const DrinkSpec &get(DrinkType t);

private:
  static inline std::unordered_map<FoodType, FoodSpec> foodTable;
  static inline std::unordered_map<DrinkType, DrinkSpec> drinkTable;
};
