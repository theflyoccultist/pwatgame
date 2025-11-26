#pragma once

#include "MiniBoss_Lisp.hpp"
#include "MiniBoss_Windows.hpp"
#include <array>
#include <raylib.h>

class MiniBossPool {
private:
  static constexpr int MINIBOSS_POOL = 10;
  static inline std::array<Windows, MINIBOSS_POOL> windowsPool;
  static inline std::array<Lisp, MINIBOSS_POOL> lispPool;

public:
  template <typename T> static std::array<T, MINIBOSS_POOL> &poolForType();

  template <typename T> static T *getFreeMiniBoss(Vector2 pos) {
    auto &pool = poolForType<T>();
    for (auto &p : pool) {
      if (!p.isActive()) {
        p.reset(pos);
        return &p;
      }
    }
    return nullptr;
  }
};

template <>
inline std::array<Windows, MiniBossPool::MINIBOSS_POOL> &
MiniBossPool::poolForType<Windows>() {
  return windowsPool;
}

template <>
inline std::array<Lisp, MiniBossPool::MINIBOSS_POOL> &
MiniBossPool::poolForType<Lisp>() {
  return lispPool;
}
