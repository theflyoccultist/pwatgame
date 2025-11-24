#include "WeaponDatabase.hpp"
#include "ProjectileType.hpp"
#include "WeaponSpec.hpp"

static const WeaponSpec weaponTable[] = {
    {400, .6, 10, 3, 12, 1},   {260, 1.1, 66, 8, 10, 3}, {800, .1, 15, 3, 1, 2},
    {1000, 1.4, 25, 4, 12, 0}, {160, .8, 30, 11, 4, 1},
};

const WeaponSpec &WeaponDataBase::get(ProjectileType type) {
  return weaponTable[static_cast<int>(type)];
}
