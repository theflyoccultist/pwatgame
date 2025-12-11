#pragma once

#include "Proj.Hellfire.hpp"
#include "Proj_Grenade.hpp"
#include "Proj_LongRange.hpp"
#include "Proj_SlowCannon.hpp"
#include "Proj_Straight.hpp"
#include "Proj_Uzi.hpp"
#include "Proj_rocket.hpp"
#include "WeaponSpec.hpp"
#include <array>

class ProjectilePool {
private:
  static constexpr int BULLET_POOL = 350;
  static inline std::array<Straight, BULLET_POOL> straightPool;
  static inline std::array<LongRange, BULLET_POOL> longRangePool;
  static inline std::array<SlowCannon, BULLET_POOL> slowCannonPool;
  static inline std::array<Rocket, BULLET_POOL> rocketPool;
  static inline std::array<Uzi, BULLET_POOL> uziPool;
  static inline std::array<Hellfire, BULLET_POOL> hellfirePool;
  static inline std::array<Grenade, BULLET_POOL> grenadePool;

public:
  template <typename T> static std::array<T, BULLET_POOL> &poolForType();

  template <typename T>
  static T *getFreeProjectile(Faction f, Vector2 pos, Vector2 dir,
                              WeaponSpec spec) {
    auto &pool = poolForType<T>();
    for (auto &p : pool) {
      if (!p.isActive()) {
        p.reset(f, pos, dir, spec);
        return &p;
      }
    }
    return nullptr;
  }
};

template <>
inline std::array<Straight, ProjectilePool::BULLET_POOL> &
ProjectilePool::poolForType<Straight>() {
  return straightPool;
}

template <>
inline std::array<LongRange, ProjectilePool::BULLET_POOL> &
ProjectilePool::poolForType<LongRange>() {
  return longRangePool;
}

template <>
inline std::array<SlowCannon, ProjectilePool::BULLET_POOL> &
ProjectilePool::poolForType<SlowCannon>() {
  return slowCannonPool;
}

template <>
inline std::array<Rocket, ProjectilePool::BULLET_POOL> &
ProjectilePool::poolForType<Rocket>() {
  return rocketPool;
}

template <>
inline std::array<Uzi, ProjectilePool::BULLET_POOL> &
ProjectilePool::poolForType<Uzi>() {
  return uziPool;
}

template <>
inline std::array<Hellfire, ProjectilePool::BULLET_POOL> &
ProjectilePool::poolForType<Hellfire>() {
  return hellfirePool;
}

template <>
inline std::array<Grenade, ProjectilePool::BULLET_POOL> &
ProjectilePool::poolForType<Grenade>() {
  return grenadePool;
}
