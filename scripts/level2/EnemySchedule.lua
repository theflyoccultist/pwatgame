-- enemy x and y position, type, and delay before spawning can be scripted.
local spawn = require("common.enemy_spawn_patterns")

EnemySpawns = {}

spawn.append(EnemySpawns, spawn.monitor_circle(12))
