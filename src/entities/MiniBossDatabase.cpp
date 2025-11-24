#include "MiniBossDatabase.hpp"
#include "../projectiles/WeaponDatabase.hpp"

static const MiniBossSpec miniBossTable[] = {
    {1000, 15, ProjectileType::STRAIGHT,
     WeaponDataBase::get(ProjectileType::STRAIGHT)},

    {2000, 150, ProjectileType::LONGRANGE,
     WeaponDataBase::get(ProjectileType::LONGRANGE)},
};
