#pragma once

#include <entities/MiniBossSpec.hpp>
#include <entities/MiniBoss_Java.hpp>
#include <entities/MiniBoss_Lisp.hpp>
#include <entities/MiniBoss_Rust.hpp>
#include <entities/MiniBoss_Windows.hpp>

#include <array>
#include <raylib.h>

class MiniBossPool {
private:
  static constexpr int MINIBOSS_POOL = 10;
  static inline std::array<Windows, MINIBOSS_POOL> windowsPool;
  static inline std::array<Lisp, MINIBOSS_POOL> lispPool;
  static inline std::array<Java, MINIBOSS_POOL> javaPool;
  static inline std::array<Rust, MINIBOSS_POOL> rustPool;

public:
  template <typename T> static std::array<T, MINIBOSS_POOL> &poolForType();

  template <typename T>
  static T *getFreeMiniBoss(Vector2 pos, const MiniBossSpec &spec) {
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
inline std::array<Windows, MiniBossPool::MINIBOSS_POOL> &
MiniBossPool::poolForType<Windows>() {
  return windowsPool;
}

template <>
inline std::array<Lisp, MiniBossPool::MINIBOSS_POOL> &
MiniBossPool::poolForType<Lisp>() {
  return lispPool;
}

template <>
inline std::array<Java, MiniBossPool::MINIBOSS_POOL> &
MiniBossPool::poolForType<Java>() {
  return javaPool;
}

template <>
inline std::array<Rust, MiniBossPool::MINIBOSS_POOL> &
MiniBossPool::poolForType<Rust>() {
  return rustPool;
}
