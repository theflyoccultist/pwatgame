#include <lua.hpp>

class LuaWrapper {
public:
  LuaWrapper();
  ~LuaWrapper();

  static int opNum(lua_State *L);
  static int convertNum(lua_State *L);

  void luaopen_pwatlib(lua_State *L);

private:
  lua_State *L;
};
