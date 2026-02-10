local spawn = require("common.enemy_spawn_patterns")

-- enemy x and y position, type, and delay before spawning can be scripted.

EnemySpawns = {
	{ x = 10, y = 30, delay = 0, type = "godsip" },
	{ x = 300, y = 300, delay = 1, type = "constrainer" },
	{ x = 320, y = 480, delay = 1, type = "constrainer" },
	{ x = 10, y = 510, delay = 1, type = "constrainer" },
	{ x = 120, y = 190, delay = 1, type = "constrainer" },
	{ x = 650, y = 340, delay = 1, type = "constrainer" },
	{ x = 200, y = 460, delay = 1, type = "constrainer" },
	{ x = 300, y = 700, delay = 1, type = "constrainer" },

	{ x = 300, y = 100, delay = 10, type = "wall" },
	{ x = 600, y = 400, delay = 10, type = "wall" },
	{ x = 400, y = 600, delay = 10, type = "wall" },
	{ x = 150, y = 350, delay = 10, type = "wall" },
	{ x = 600, y = 300, delay = 16, type = "wall" },
	{ x = 450, y = 200, delay = 16, type = "wall" },
	{ x = 400, y = 200, delay = 16, type = "wall" },
	{ x = 150, y = 50, delay = 16, type = "wall" },

	{ x = 600, y = 100, delay = 17, type = "sniper" },
	{ x = 562, y = 151, delay = 17, type = "sniper" },
	{ x = 702, y = 191, delay = 17, type = "sniper" },
	{ x = 662, y = 81, delay = 17, type = "sniper" },
	{ x = 512, y = 24, delay = 17, type = "sniper" },

	{ x = 59, y = 452, delay = 19, type = "wall" },
	{ x = 180, y = 480, delay = 19, type = "wall" },
	{ x = 310, y = 430, delay = 19, type = "wall" },
	{ x = 522, y = 449, delay = 19, type = "wall" },

	{ x = 691, y = 712, delay = 21, type = "godsip" },
	{ x = 188, y = 712, delay = 21, type = "godsip" },
	--	{ x = 10, y = 10, delay = 26, type = "wallmove" },
}

spawn.append(EnemySpawns, spawn.horizontal_walls(-100, 300, 26, 0.1))
spawn.append(EnemySpawns, spawn.vertical_walls(400, -100, 26.8, 0.2))
spawn.append(EnemySpawns, spawn.vertical_walls(200, 300, 27.4, 0.4))
spawn.append(EnemySpawns, spawn.horizontal_walls(-100, 100, 27.4, 0.2))
spawn.append(EnemySpawns, spawn.vertical_walls(500, -100, 31.4, 0.2))
