#pragma once

#include "EnemySpec.hpp"
#include "Enemy_Duo.hpp"
#include "Enemy_Godsip.hpp"
#include "Enemy_Monitor.hpp"
#include "Enemy_Sniper.hpp"
#include "Enemy_Swarmer.hpp"
#include "Enemy_Zomb.hpp"
#include <array>
#include <raylib.h>

class EnemyPool {
private:
  static constexpr int ENEMY_POOL = 350;
  static inline std::array<Godsip, ENEMY_POOL> godsipPool;
  static inline std::array<Monitor, ENEMY_POOL> monitorPool;
  static inline std::array<Sniper, ENEMY_POOL> sniperPool;
  static inline std::array<Swarmer, ENEMY_POOL> swarmerPool;
  static inline std::array<Zomb, ENEMY_POOL> zombPool;
  static inline std::array<Duo, ENEMY_POOL> duoPool;

public:
  template <typename T> static std::array<T, ENEMY_POOL> &poolForType();

  template <typename T>
  static T *getFreeEnemy(Vector2 pos, const EnemySpec &spec) {
    auto &pool = poolForType<T>();
    for (auto &p : pool) {
      if (!p.isActive()) {
        p.reset(pos, spec);
        p.setTexture();
        return &p;
      }
    }
    return nullptr;
  }
};

template <>
inline std::array<Godsip, EnemyPool::ENEMY_POOL> &
EnemyPool::poolForType<Godsip>() {
  return godsipPool;
}

template <>
inline std::array<Monitor, EnemyPool::ENEMY_POOL> &
EnemyPool::poolForType<Monitor>() {
  return monitorPool;
}

template <>
inline std::array<Sniper, EnemyPool::ENEMY_POOL> &
EnemyPool::poolForType<Sniper>() {
  return sniperPool;
}

template <>
inline std::array<Swarmer, EnemyPool::ENEMY_POOL> &
EnemyPool::poolForType<Swarmer>() {
  return swarmerPool;
}

template <>
inline std::array<Zomb, EnemyPool::ENEMY_POOL> &EnemyPool::poolForType<Zomb>() {
  return zombPool;
}

template <>
inline std::array<Duo, EnemyPool::ENEMY_POOL> &EnemyPool::poolForType<Duo>() {
  return duoPool;
}
