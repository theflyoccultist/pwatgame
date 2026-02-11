local wall = require("common.wall_spawn_patterns")

WallSpawns = {
	{
		x = 300,
		y = 100,
		type = "immobile",
		size = 100,
		warningTime = 3.6,
		activeTime = 3.6,
		contactDmg = 30,
		delay = 10,
	},
	{
		x = 600,
		y = 400,
		type = "immobile",
		size = 100,
		warningTime = 3.6,
		activeTime = 3.6,
		contactDmg = 30,
		delay = 10,
	},
	{
		x = 400,
		y = 600,
		type = "immobile",
		size = 100,
		warningTime = 3.6,
		activeTime = 3.6,
		contactDmg = 30,
		delay = 10,
	},
	{
		x = 150,
		y = 350,
		type = "immobile",
		size = 100,
		warningTime = 3.6,
		activeTime = 3.6,
		contactDmg = 30,
		delay = 10,
	},
	{
		x = 600,
		y = 300,
		type = "immobile",
		size = 100,
		warningTime = 3.6,
		activeTime = 3.6,
		contactDmg = 30,
		delay = 16,
	},
	{
		x = 450,
		y = 200,
		type = "immobile",
		size = 100,
		warningTime = 3.6,
		activeTime = 3.6,
		contactDmg = 30,
		delay = 16,
	},
	{
		x = 400,
		y = 200,
		type = "immobile",
		size = 100,
		warningTime = 3.6,
		activeTime = 3.6,
		contactDmg = 30,
		delay = 16,
	},
	{
		x = 150,
		y = 50,
		type = "immobile",
		size = 100,
		warningTime = 3.6,
		activeTime = 3.6,
		contactDmg = 30,
		delay = 16,
	},

	{
		x = 59,
		y = 452,
		type = "immobile",
		size = 100,
		warningTime = 3.6,
		activeTime = 3.6,
		contactDmg = 30,
		delay = 19,
	},
	{
		x = 180,
		y = 480,
		type = "immobile",
		size = 100,
		warningTime = 3.6,
		activeTime = 3.6,
		contactDmg = 30,
		delay = 19,
	},
	{
		x = 310,
		y = 430,
		type = "immobile",
		size = 100,
		warningTime = 3.6,
		activeTime = 3.6,
		contactDmg = 30,
		delay = 19,
	},
	{
		x = 522,
		y = 449,
		type = "immobile",
		size = 100,
		warningTime = 3.6,
		activeTime = 3.6,
		contactDmg = 30,
		delay = 19,
	},
}

wall.append(WallSpawns, wall.horizontal_walls(-100, 300, 26, 0.1))
wall.append(WallSpawns, wall.vertical_walls(400, -100, 26.8, 0.2))
wall.append(WallSpawns, wall.vertical_walls(200, 300, 27.4, 0.4))
wall.append(WallSpawns, wall.horizontal_walls(-100, 100, 27.4, 0.2))

wall.append(WallSpawns, wall.vertical_walls(500, -100, 32, 0))
wall.append(WallSpawns, wall.horizontal_walls(-100, 300, 32.5, 0.2))
wall.append(WallSpawns, wall.vertical_walls(300, -100, 32, 0.3))
