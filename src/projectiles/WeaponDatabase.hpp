#include "ProjectileType.hpp"
#include "WeaponSpec.hpp"

class WeaponDataBase {
public:
  static const WeaponSpec &get(ProjectileType t);
};
