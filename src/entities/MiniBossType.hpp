#pragma once

#include <cstdint>
#include <ostream>

enum class MiniBossType : uint8_t { WINDOWS, LISP, JAVA, RUST };

inline std::ostream &operator<<(std::ostream &os, MiniBossType type) {
  switch (type) {
  case MiniBossType::WINDOWS:
    os << "Windows";
    break;
  case MiniBossType::LISP:
    os << "Lisp";
    break;
  case MiniBossType::JAVA:
    os << "Java";
    break;
  case MiniBossType::RUST:
    os << "Rust";
    break;
  }

  return os;
}
