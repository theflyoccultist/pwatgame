-- enemy x and y position, type, and delay before spawning can be scripted.
local spawn = require("common.enemy_spawn_patterns")

EnemySpawns = {
	{ x = 400, y = 100, delay = 9, type = "fractal" },
}

spawn.append(EnemySpawns, spawn.zomb_chaos(10, 0))
