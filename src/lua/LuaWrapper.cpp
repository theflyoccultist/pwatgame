#include "LuaWrapper.hpp"
#include <expected>
#include <iostream>
#include <string>

std::ostream &operator<<(std::ostream &os, const LuaError err) {
  switch (err) {
  case LuaError::FileOpenError:
    os << "File not found";
    break;
  case LuaError::RuntimeError:
    os << "Lua runtime error";
    break;
  case LuaError::IntegerNotFound:
    os << "Lua integer not found";
    break;
  case LuaError::NumberNotFound:
    os << "Lua number not found";
    break;
  case LuaError::StringNotFound:
    os << "Lua string not found";
    break;
  default:
    os << "Unknown Lua error";
    break;
  }
  return os;
};

LuaResult LuaWrapper::runFile(const char *filename) {
  if (luaL_dofile(L, filename) != LUA_OK) {
    lua_pop(L, 1);
    return std::unexpected(LuaError::FileOpenError);
  }

  if (lua_pcall(L, 0, LUA_MULTRET, 0) != LUA_OK) {
    std::cerr << lua_tostring(L, -1) << "\n";
    lua_pop(L, 1);
    return std::unexpected(LuaError::RuntimeError);
  }

  return {};
}

LuaResultT<int> LuaWrapper::getInt(const char *key) {
  lua_getfield(L, -1, key);

  if (!lua_isinteger(L, -1)) {
    lua_pop(L, 1);
    return std::unexpected(LuaError::IntegerNotFound);
  }

  int value = lua_tointeger(L, -1);
  lua_pop(L, 1);
  return value;
}

LuaResultT<double> LuaWrapper::getNumber(const char *key) {
  lua_getfield(L, -1, key);

  if (!lua_isnumber(L, -1)) {
    lua_pop(L, 1);
    return std::unexpected(LuaError::NumberNotFound);
  }

  int value = lua_tonumber(L, -1);
  lua_pop(L, 1);
  return value;
}

LuaResultT<std::string> LuaWrapper::getString(const char *key) {
  lua_getfield(L, -1, key);

  if (!lua_isstring(L, -1)) {
    lua_pop(L, 1);
    return std::unexpected(LuaError::StringNotFound);
  }

  std::string value = lua_tostring(L, -1);
  lua_pop(L, 1);
  return value;
}

EnemyType enemyTypeFromString(std::string_view s) {
  if (s == "godsip")
    return EnemyType::GODSIP;
  if (s == "monitor")
    return EnemyType::MONITOR;
  if (s == "sniper")
    return EnemyType::SNIPER;
  if (s == "swarmer")
    return EnemyType::SWARMER;
  if (s == "zomb")
    return EnemyType::ZOMB;

  return EnemyType::ZOMB;
}
