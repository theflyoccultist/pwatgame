#include "EnemyDatabase.hpp"
#include "../projectiles/WeaponDatabase.hpp"
#include "EnemyType.hpp"

static const EnemySpec EnemyTable[] = {
    {50, 60}, {150, 30}, {200, 100}, {70, 40}, {300, 10},
};

const EnemySpec &EnemyDatabase::get(EnemyType e) {
  return EnemyTable[static_cast<int>(e)];
};

ProjectileType EnemyDatabase::getWeaponType(EnemyType e) {
  switch (e) {
  case EnemyType::SWARMER:
    return ProjectileType::UZI;
  case EnemyType::SNIPER:
    return ProjectileType::LONGRANGE;
  case EnemyType::GODSIP:
    return ProjectileType::STRAIGHT;
  case EnemyType::ZOMB:
    return ProjectileType::SLOWCANNON;
  case EnemyType::MONITOR:
    return ProjectileType::ROCKET;
  default:
    return ProjectileType::UZI;
  }
}

WeaponSpec EnemyDatabase::getWeaponSpec(EnemyType e) {
  ProjectileType pt = getWeaponType(e);
  return WeaponDataBase::get(pt);
}
