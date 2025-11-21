#include "LuaWrapper.hpp"
#include <expected>
#include <lua.h>
#include <string>

std::ostream &operator<<(std::ostream &os, const LuaError err) {
  switch (err) {
  case LuaError::FileNotFound:
    os << "File not found";
    break;
  case LuaError::SyntaxError:
    os << "Lua syntax error";
    break;
  case LuaError::RuntimeError:
    os << "Lua runtime error";
    break;
  case LuaError::TypeError:
    os << "Lua type mismatch";
    break;
  case LuaError::MissingField:
    os << "Missing required field";
    break;
  case LuaError::InvalidValue:
    os << "Invalid value";
    break;
  case LuaError::StackCorruption:
    os << "Lua stack corruption";
    break;
  case LuaError::CFunctionError:
    os << "C function threw an error";
    break;
  default:
    os << "Unknown Lua error";
    break;
  }
  return os;
};

LuaWrapper::LuaWrapper() {
  lua_State *L = luaL_newstate();
  luaL_openlibs(L);
};

LuaWrapper::~LuaWrapper() {
  if (L)
    lua_close(L);
};

LuaResult LuaWrapper::runFile(const std::string &file) {
  if (luaL_dofile(L, file.c_str()) != LUA_OK) {
    lua_pop(L, 1);
    return std::unexpected(LuaError::FileNotFound);
  }
  return {};
}

LuaResultT<int> LuaWrapper::getInt(lua_State *L, const char *key) {
  lua_getfield(L, -1, key);

  if (!lua_isinteger(L, -1)) {
    lua_pop(L, 1);
    return std::unexpected(LuaError::TypeError);
  }

  int value = lua_tointeger(L, -1);
  lua_pop(L, -1);
  return value;
}

LuaResultT<std::string> getString(lua_State *L, const char *key) {
  lua_getfield(L, -1, key);

  if (!lua_isstring(L, -1)) {
    lua_pop(L, 1);
    return std::unexpected(LuaError::TypeError);
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
