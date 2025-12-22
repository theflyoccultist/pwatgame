-- enemy x and y position, type, and delay before spawning can be scripted.
local spawn = require("common.enemy_spawn_patterns")

EnemySpawns = {}

spawn.append(EnemySpawns, spawn.monitor_circle(12))
spawn.append(EnemySpawns, spawn.godsip_cardinal(12))
spawn.append(EnemySpawns, spawn.godsip_cardinal(16))
spawn.append(EnemySpawns, spawn.godsip_cardinal(20))
