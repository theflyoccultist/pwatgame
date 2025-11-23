#pragma once

#include "../entities/Enemy.hpp"
#include <cstdint>
#include <expected>
#include <lua.hpp>
#include <ostream>
#include <string>

enum class LuaError : uint8_t {
  FileOpenError,
  RuntimeError,
  SyntaxError,
  TypeError,
  IntegerNotFound,
  NumberNotFound,
  StringNotFound,
};

std::ostream &operator<<(std::ostream &os, const LuaError &err);

template <typename T> using LuaResultT = std::expected<T, LuaError>;

class LuaWrapper {
public:
  LuaWrapper() {
    L = luaL_newstate();
    luaL_openlibs(L);
  }
  ~LuaWrapper() {
    if (L)
      lua_close(L);
  };

  lua_State *getState() { return L; }

  LuaResultT<void> runFile(const char *filename);
  LuaResultT<void> getTable(const char *name);
  LuaResultT<long long> getInt(const char *key);
  LuaResultT<double> getNumber(const char *key);
  LuaResultT<std::string> getString(const char *key);

  EnemyType enemyTypeFromString(std::string_view s);

private:
  lua_State *L;
};
