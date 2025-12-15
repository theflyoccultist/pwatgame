local spawn = require("common.spawn_patterns")

EnemySpawns = {}

spawn.append(EnemySpawns, spawn.swarmer_swarm(4, 10, 30, 50, 10, 5, 1.5))
spawn.append(EnemySpawns, spawn.swarmer_swarm(4, 480, 700, 10, 60, 5, 1.5))
spawn.append(EnemySpawns, spawn.zomb_chaos(10, 0, 0))
