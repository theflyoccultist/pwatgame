local spawn = require("common.enemy_spawn_patterns")

EnemySpawns = {}

spawn.append(EnemySpawns, spawn.zomb_chaos(10, 0))
spawn.append(EnemySpawns, spawn.swarmer_swarm(2, -210, 30, 50, 10, 5, 1.5))
spawn.append(EnemySpawns, spawn.swarmer_swarm(2, 480, 700, 10, 60, 5, 1.5))
spawn.append(EnemySpawns, spawn.monitor_circle(12))
spawn.append(EnemySpawns, spawn.godsip_cardinal(12))
spawn.append(EnemySpawns, spawn.godsip_cardinal(18))
spawn.append(EnemySpawns, spawn.godsip_cardinal(24))
spawn.append(EnemySpawns, spawn.zomb_chaos(5, 31, 0.6))
spawn.append(EnemySpawns, spawn.sniper_squad(5, 135, 10, 100, 150, 37))
