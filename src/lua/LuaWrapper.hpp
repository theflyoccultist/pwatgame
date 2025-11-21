#pragma once

#include "../entities/Enemy.hpp"
#include <cstdint>
#include <expected>
#include <lua.hpp>
#include <ostream>
#include <string>
#include <string_view>

enum class LuaError : uint8_t {
  FileNotFound,
  SyntaxError,
  RuntimeError,
  TypeError,
  MissingField,
  InvalidValue,
  StackCorruption,
  CFunctionError,
};

std::ostream &operator<<(std::ostream &os, const LuaError &err);

using LuaResult = std::expected<void, LuaError>;
template <typename T> using LuaResultT = std::expected<T, LuaError>;

class LuaWrapper {
public:
  LuaWrapper();
  ~LuaWrapper();

  LuaResult runFile(const std::string &file);
  LuaResultT<int> getInt(lua_State *L, const char *key);
  LuaResultT<std::string> getString(lua_State *L, const char *key);

  EnemyType enemyTypeFromString(std::string_view s);

private:
  lua_State *L;
};
