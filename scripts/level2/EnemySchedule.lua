-- enemy x and y position, type, and delay before spawning can be scripted.
local spawn = require("common.enemy_spawn_patterns")

EnemySpawns = {
	{ x = 400, y = 100, delay = 9, type = "fractal" },
	{ x = 120, y = 50, delay = 15, type = "sniper" },
	{ x = 207, y = 35, delay = 15, type = "sniper" },
	{ x = 289, y = 77, delay = 15, type = "sniper" },
	{ x = 311, y = 102, delay = 15, type = "sniper" },
	{ x = 369, y = 143, delay = 15, type = "sniper" },
	{ x = 409, y = 13, delay = 15, type = "sniper" },
	{ x = 400, y = 100, delay = 46, type = "fractal" },
}

spawn.append(EnemySpawns, spawn.zomb_chaos(10, 0))
spawn.append(EnemySpawns, spawn.monitor_circle(18))
spawn.append(EnemySpawns, spawn.zomb_chaos(10, 32))
spawn.append(EnemySpawns, spawn.monitor_circle(41))
spawn.append(EnemySpawns, spawn.godsip_cardinal(49))
-- todo : add new enemy type around 59 seconds
