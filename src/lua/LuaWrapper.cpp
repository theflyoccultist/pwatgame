#include "LuaWrapper.hpp"

LuaWrapper::LuaWrapper() {
  lua_State *L = luaL_newstate();
  luaL_openlibs(L);
};

LuaWrapper::~LuaWrapper() { lua_close(L); };

int LuaWrapper::opNum(lua_State *L) {
  auto arg = luaL_checkinteger(L, 1);

  auto result = arg * 2;

  lua_pushinteger(L, result);

  return 1;
}

int LuaWrapper::convertNum(lua_State *L) {
  long long num = lua_tointeger(L, -1);

  return 1;
}

void LuaWrapper::luaopen_pwatlib(lua_State *L) {
  lua_register(L, "opNum", opNum);
  lua_register(L, "convertNum", convertNum);
}
