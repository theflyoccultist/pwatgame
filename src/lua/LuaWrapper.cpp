#include "LuaWrapper.hpp"
#include <expected>
#include <iostream>
#include <string>

std::ostream &operator<<(std::ostream &os, const LuaError &err) {
  switch (err) {
  case LuaError::FileOpenError:
    os << "Lua error: File not found";
    break;
  case LuaError::RuntimeError:
    os << "Lua runtime error";
    break;
  case LuaError::SyntaxError:
    os << "Lua Syntax error";
    break;
  case LuaError::TableError:
    os << "Lua Table error";
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

void LuaWrapper::initLua() {
  lua_getglobal(L, "package");
  lua_getfield(L, -1, "path");

  std::string path = lua_tostring(L, -1);
  path = "../scripts/?.lua;../scripts/?/init.lua;" + path;

  lua_pop(L, 1);
  lua_pushstring(L, path.c_str());
  lua_setfield(L, -2, "path");
  lua_pop(L, 1);
  std::cout << "Lua Initialized\n";
  std::cout << path << "\n";
}

LuaResultT<void> LuaWrapper::runFile(const char *filename) {
  if (luaL_dofile(L, filename) != LUA_OK) {
    std::cerr << lua_tostring(L, -1) << "\n";
    lua_pop(L, 1);
    return std::unexpected(LuaError::FileOpenError);
  }

  return {};
}

LuaResultT<void> LuaWrapper::getTable(const char *name) {
  lua_getglobal(L, name);

  if (!lua_istable(L, -1)) {
    lua_pop(L, 1);
    return std::unexpected(LuaError::TableError);
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

LuaResultT<float> LuaWrapper::getNumber(const char *key) {
  lua_getfield(L, -1, key);

  if (!lua_isnumber(L, -1)) {
    lua_pop(L, 1);
    return std::unexpected(LuaError::NumberNotFound);
  }

  float value = (float)lua_tonumber(L, -1);
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
