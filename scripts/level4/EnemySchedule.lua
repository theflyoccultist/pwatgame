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
