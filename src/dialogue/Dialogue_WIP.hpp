// Not added to the game yet: a dialogue system

#pragma once

#include "../lua/LuaWrapper.hpp"
#include <expected>
#include <iostream>
#include <string>
#include <vector>

class Dialogue {
public:
  std::vector<std::string> lines{};

  void parseDialogue(LuaWrapper &lua, const char *filename) {
    lines.clear();

    lua.runFile(filename).or_else([](LuaError e) {
      std::cerr << e << "\n";
      return std::expected<void, LuaError>();
    });

    lua.getTable("Dialogue")
        .and_then([&]() -> LuaResultT<void> {
          lua_getfield(lua.getState(), -1, "lines");

          if (!lua_istable(lua.getState(), -1)) {
            lua_pop(lua.getState(), 1);
            return std::unexpected(LuaError::TableError);
          }

          int len = (int)lua_rawlen(lua.getState(), -1);

          for (int i = 1; i <= len; i++) {
            lua_rawgeti(lua.getState(), -1, i);

            if (lua_isstring(lua.getState(), -1)) {
              lines.emplace_back(lua_tostring(lua.getState(), -1));
            } else {
              lines.emplace_back("dialogue line missing");
            }
            lua_pop(lua.getState(), 1);
          }

          lua_pop(lua.getState(), 1);
          return {};
        })

        .or_else([](LuaError e) {
          std::cerr << "Expected dialogue table: " << e << "\n";
          return std::expected<void, LuaError>();
        });

    for (auto &l : lines)
      std::cout << l << "\n";
  }
};
