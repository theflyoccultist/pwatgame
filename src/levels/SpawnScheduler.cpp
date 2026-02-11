#include "SpawnScheduler.hpp"
#include "../entities/WallSpec.hpp"
#include "../lua/TypeFromString.hpp"
#include <expected>
#include <iostream>
#include <raylib.h>
#include <string_view>
#include <vector>

void SpawnScheduler::scheduleEnemies(const char *filename) {
  struct spawnEnemy {
    Vector2 pos;
    double delay;
    EnemyType type;
  };

  std::vector<spawnEnemy> waves{};

  lua.runFile(filename).or_else([](LuaError e) {
    std::cerr << e << "\n";
    return std::expected<void, LuaError>();
  });

  lua.getTable("EnemySpawns")
      .and_then([&](void) -> LuaResultT<void> {
        int len = (int)lua_rawlen(lua.getState(), -1);

        for (int i = 1; i <= len; i++) {
          lua_rawgeti(lua.getState(), -1, i);

          spawnEnemy wave;

          wave.pos = {static_cast<float>(lua.getInt("x").value_or(0)),
                      static_cast<float>(lua.getInt("y").value_or(0))};

          wave.delay = lua.getNumber("delay").value_or(0.0);

          wave.type = lua.getString("type")
                          .transform([&](const std::string_view &s) {
                            return TypeFromString::enemyTypeFromString(s);
                          })
                          .value_or(EnemyType::ZOMB);

          waves.push_back(wave);

          lua_pop(lua.getState(), 1);
        }

        std::cout
            << "Spawn Scheduler - Successfully loaded lua script for enemies: "
            << filename << "\n";
        return {};
      })

      .or_else([](LuaError e) {
        std::cerr << "Expected spawn table: " << e << "\n";
        return std::expected<void, LuaError>();
      });

  for (auto &wave : waves) {
    sm.scheduler.schedule(wave.delay, [pos = wave.pos, type = wave.type, this] {
      world.enemyManager.spawnEnemy(pos, type);
    });
  }
}

void SpawnScheduler::scheduleWalls(const char *filename) {
  struct spawnWall : public WallSpec {
    Vector2 pos;
    WallType type;
    float delay;
  };

  std::vector<spawnWall> walls{};

  lua.runFile(filename).or_else([](LuaError e) {
    std::cerr << e << "\n";
    return std::expected<void, LuaError>();
  });

  lua.getTable("WallSpawns")
      .and_then([&](void) -> LuaResultT<void> {
        int len = (int)lua_rawlen(lua.getState(), -1);

        for (int i = 1; i <= len; i++) {
          lua_rawgeti(lua.getState(), -1, i);

          spawnWall wall;

          wall.pos = {static_cast<float>(lua.getInt("x").value_or(0)),
                      static_cast<float>(lua.getInt("y").value_or(0))};

          wall.type = lua.getString("type")
                          .transform([&](const std::string_view &s) {
                            return TypeFromString::wallTypeFromString(s);
                          })
                          .value_or(WallType::IMMOBILE);

          wall.axis = lua.getString("axis")
                          .transform([&](const std::string_view &s) {
                            return TypeFromString::wallAxisFromString(s);
                          })
                          .value_or(MoveAxis::Horizontal);

          wall.speed = lua.getNumber("speed").value_or(0.0f);
          wall.size = lua.getNumber("size").value_or(100.0f);
          wall.warningTime = lua.getNumber("warningTime").value_or(1.0f);
          wall.activeTime = lua.getNumber("activeTime").value_or(1.0f);
          wall.contactDmg = lua.getInt("contactDmg").value_or(1);

          wall.delay = lua.getNumber("delay").value_or(0.0f);

          walls.push_back(wall);

          lua_pop(lua.getState(), 1);
        }

        std::cout
            << "Spawn Scheduler - Successfully loaded lua script for Walls: "
            << filename << "\n";

        return {};
      })

      .or_else([](LuaError e) {
        std::cerr << "Expected spawn table: " << e << "\n";
        return std::expected<void, LuaError>();
      });

  for (auto &wall : walls) {
    sm.scheduler.schedule(wall.delay, [pos = wall.pos, type = wall.type,
                                       axis = wall.axis, speed = wall.speed,
                                       size = wall.size,
                                       warningTime = wall.warningTime,
                                       activeTime = wall.activeTime,
                                       contactDmg = wall.contactDmg, this] {
      world.wallManager.spawnWall(
          type, pos, {axis, speed, size, warningTime, activeTime, contactDmg});
    });
  }
}

void SpawnScheduler::scheduleMiniBoss(const char *filename) {
  struct spawnMiniBoss {
    MiniBossType type;
    float delay;
  };

  std::vector<spawnMiniBoss> waves{};

  lua.runFile(filename).or_else([](LuaError e) {
    std::cerr << e << "\n";
    return std::expected<void, LuaError>();
  });

  lua.getTable("MinibossSpawns")
      .and_then([&](void) -> LuaResultT<void> {
        int len = (int)lua_rawlen(lua.getState(), -1);

        for (int i = 1; i <= len; i++) {
          lua_rawgeti(lua.getState(), -1, i);

          spawnMiniBoss wave;

          wave.type = lua.getString("type")
                          .transform([&](const std::string_view &s) {
                            return TypeFromString::mbTypeFromString(s);
                          })
                          .value_or(MiniBossType::LISP);

          wave.delay = lua.getNumber("delay").value_or(200.0f);

          waves.push_back(wave);

          lua_pop(lua.getState(), 1);

          std::cout << "Miniboss to spawn: " << wave.type
                    << " at: " << wave.delay << " seconds\n";
        }

        std::cout
            << "Spawn Scheduler - Successfully loaded lua script for Miniboss: "
            << filename << "\n";

        return {};
      })

      .or_else([](LuaError e) {
        std::cerr << "Expected spawn table: " << e << "\n";
        return std::expected<void, LuaError>();
      });

  for (auto &wave : waves) {
    sm.scheduler.schedule(wave.delay, [type = wave.type, this] {
      world.minibossManager.spawnMiniBoss(type);
    });
  }
}
