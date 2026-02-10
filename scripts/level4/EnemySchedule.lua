local spawn = require("common.enemy_spawn_patterns")

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

	{ x = 60, y = 500, delay = 31, type = "sniper" },
	{ x = 90, y = 612, delay = 31, type = "sniper" },
	{ x = 110, y = 633, delay = 31, type = "sniper" },
	{ x = 140, y = 671, delay = 31, type = "sniper" },
	{ x = 88, y = 559, delay = 31, type = "sniper" },

	{ x = 59, y = 452, delay = 19, type = "wall" },
	{ x = 180, y = 480, delay = 19, type = "wall" },
	{ x = 310, y = 430, delay = 19, type = "wall" },
	{ x = 522, y = 449, delay = 19, type = "wall" },

	{ x = 691, y = 712, delay = 21, type = "godsip" },
	{ x = 188, y = 712, delay = 21, type = "godsip" },
	--	{ x = 10, y = 10, delay = 26, type = "wallmove" },

	{ x = 300, y = 300, delay = 35, type = "constrainer" },
	{ x = 320, y = 480, delay = 35, type = "constrainer" },
	{ x = 10, y = 510, delay = 35, type = "constrainer" },
	{ x = 120, y = 190, delay = 35, type = "constrainer" },
}

-- function M.swarm(type, count, start_x, start_y, dx, dy, delay, delay_step)
spawn.append(EnemySpawns, spawn.swarm("sniper", 5, 512, 24, 60, 60, 17, 0))
spawn.append(EnemySpawns, spawn.swarm("sniper", 5, 69, 600, 39, 39, 31, 0))

spawn.append(EnemySpawns, spawn.horizontal_walls(-100, 300, 26, 0.1))
spawn.append(EnemySpawns, spawn.vertical_walls(400, -100, 26.8, 0.2))
spawn.append(EnemySpawns, spawn.vertical_walls(200, 300, 27.4, 0.4))
spawn.append(EnemySpawns, spawn.horizontal_walls(-100, 100, 27.4, 0.2))

spawn.append(EnemySpawns, spawn.vertical_walls(500, -100, 32, 0))
spawn.append(EnemySpawns, spawn.horizontal_walls(-100, 300, 32.5, 0.2))
spawn.append(EnemySpawns, spawn.vertical_walls(300, -100, 32, 0.3))
