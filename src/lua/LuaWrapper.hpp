#pragma once

#include "../entities/Enemy.hpp"
#include <cstdint>
#include <expected>
#include <lua.hpp>
#include <ostream>
#include <string_view>

enum class LuaError : uint8_t {
  FileOpenError,
  RuntimeError,
  IntegerNotFound,
  NumberNotFound,
  StringNotFound,
};

std::ostream &operator<<(std::ostream &os, const LuaError &err);

using LuaResult = std::expected<void, LuaError>;
template <typename T> using LuaResultT = std::expected<T, LuaError>;

class LuaWrapper {
public:
  LuaWrapper() : L{luaL_newstate()} { luaL_openlibs(L); }
  ~LuaWrapper() {
    if (L)
      lua_close(L);
  };

  LuaResult runFile(const char *filename);
  LuaResultT<int> getInt(const char *key);
  LuaResultT<double> getNumber(const char *key);
  LuaResultT<std::string> getString(const char *key);

  EnemyType enemyTypeFromString(std::string_view s);

private:
  lua_State *L;
};
