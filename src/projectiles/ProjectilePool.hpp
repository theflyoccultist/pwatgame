#pragma once

#include "Proj_Elixir.hpp"
#include "Proj_Executable.hpp"
#include "Proj_Grenade.hpp"
#include "Proj_Hellfire.hpp"
#include "Proj_Internet.hpp"
#include "Proj_Lambda.hpp"
#include "Proj_LongRange.hpp"
#include "Proj_Paren.hpp"
#include "Proj_Recon.hpp"
#include "Proj_Rocket.hpp"
#include "Proj_SlowCannon.hpp"
#include "Proj_Straight.hpp"
#include "Proj_Update.hpp"
#include "Proj_Uzi.hpp"
#include "WeaponSpec.hpp"
#include <array>

class ProjectilePool {
private:
  static constexpr int BULLET_POOL = 450;
  static inline std::array<Elixir, BULLET_POOL> elixirPool;
  static inline std::array<Executable, BULLET_POOL> exePool;
  static inline std::array<Grenade, BULLET_POOL> grenadePool;
  static inline std::array<Hellfire, BULLET_POOL> hellfirePool;
  static inline std::array<Internet, BULLET_POOL> iePool;
  static inline std::array<Lambda, BULLET_POOL> lambdaPool;
  static inline std::array<LongRange, BULLET_POOL> longRangePool;
  static inline std::array<Paren, BULLET_POOL> parenPool;
  static inline std::array<Recon, BULLET_POOL> reconPool;
  static inline std::array<Rocket, BULLET_POOL> rocketPool;
  static inline std::array<SlowCannon, BULLET_POOL> slowCannonPool;
  static inline std::array<Straight, BULLET_POOL> straightPool;
  static inline std::array<Update, BULLET_POOL> updatePool;
  static inline std::array<Uzi, BULLET_POOL> uziPool;

public:
  template <typename T> static std::array<T, BULLET_POOL> &poolForType();

  template <typename T>
  static T *getFreeProjectile(Faction f, Vector2 pos, Vector2 dir,
                              WeaponSpec spec) {
    auto &pool = poolForType<T>();
    for (auto &p : pool) {
      if (!p.isActive()) {
        p.reset(f, pos, dir, spec);
        p.setTexture();
        return &p;
      }
    }
    return nullptr;
  }
};

template <>
inline std::array<Elixir, ProjectilePool::BULLET_POOL> &
ProjectilePool::poolForType<Elixir>() {
  return elixirPool;
}

template <>
inline std::array<Executable, ProjectilePool::BULLET_POOL> &
ProjectilePool::poolForType<Executable>() {
  return exePool;
}

template <>
inline std::array<Grenade, ProjectilePool::BULLET_POOL> &
ProjectilePool::poolForType<Grenade>() {
  return grenadePool;
}

template <>
inline std::array<Hellfire, ProjectilePool::BULLET_POOL> &
ProjectilePool::poolForType<Hellfire>() {
  return hellfirePool;
}

template <>
inline std::array<Internet, ProjectilePool::BULLET_POOL> &
ProjectilePool::poolForType<Internet>() {
  return iePool;
}

template <>
inline std::array<Lambda, ProjectilePool::BULLET_POOL> &
ProjectilePool::poolForType<Lambda>() {
  return lambdaPool;
}

template <>
inline std::array<LongRange, ProjectilePool::BULLET_POOL> &
ProjectilePool::poolForType<LongRange>() {
  return longRangePool;
}

template <>
inline std::array<Paren, ProjectilePool::BULLET_POOL> &
ProjectilePool::poolForType<Paren>() {
  return parenPool;
}

template <>
inline std::array<Recon, ProjectilePool::BULLET_POOL> &
ProjectilePool::poolForType<Recon>() {
  return reconPool;
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
inline std::array<Straight, ProjectilePool::BULLET_POOL> &
ProjectilePool::poolForType<Straight>() {
  return straightPool;
}

template <>
inline std::array<Update, ProjectilePool::BULLET_POOL> &
ProjectilePool::poolForType<Update>() {
  return updatePool;
}

template <>
inline std::array<Uzi, ProjectilePool::BULLET_POOL> &
ProjectilePool::poolForType<Uzi>() {
  return uziPool;
}
