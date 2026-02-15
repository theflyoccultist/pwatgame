#pragma once

#include <cstdint>
#include <ostream>

enum class ProjectileType : uint8_t {
  ELIXIR,
  EXECUTABLE,
  GRENADE,
  HELLFIRE,
  INTERNET,
  LAMBDA,
  LONGRANGE,
  PAREN,
  RECON,
  ROCKET,
  SLOWCANNON,
  STRAIGHT,
  UPDATE,
  UZI,
  WARNING,
  COUNT
};

inline std::ostream &operator<<(std::ostream &os, ProjectileType type) {
  switch (type) {
  case ProjectileType::ELIXIR:
    os << "ELIXIR";
    break;
  case ProjectileType::EXECUTABLE:
    os << "EXE";
    break;
  case ProjectileType::GRENADE:
    os << "GRENADE";
    break;
  case ProjectileType::HELLFIRE:
    os << "HELLFIRE";
    break;
  case ProjectileType::INTERNET:
    os << "INTERNET EXPLORER";
    break;
  case ProjectileType::LAMBDA:
    os << "LAMBDA";
    break;
  case ProjectileType::LONGRANGE:
    os << "LONGRANGE";
    break;
  case ProjectileType::PAREN:
    os << "LISP PARENTHESIS";
    break;
  case ProjectileType::RECON:
    os << "RECON";
    break;
  case ProjectileType::ROCKET:
    os << "ROCKET";
    break;
  case ProjectileType::SLOWCANNON:
    os << "SLOWCANNON";
    break;
  case ProjectileType::STRAIGHT:
    os << "STRAIGHT";
    break;
  case ProjectileType::UPDATE:
    os << "WINDOWS UPDATE";
    break;
  case ProjectileType::UZI:
    os << "UZI";
    break;
  default:
    os << "UNKNOWN_PROJECTILE";
    break;
  }
  return os;
}
