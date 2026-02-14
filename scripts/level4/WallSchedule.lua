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
		size = 91,
		warningTime = 3.6,
		activeTime = 3.6,
		contactDmg = 30,
		delay = 10,
	},
	{
		x = 400,
		y = 600,
		type = "immobile",
		size = 112,
		warningTime = 3.6,
		activeTime = 3.6,
		contactDmg = 30,
		delay = 10,
	},
	{
		x = 150,
		y = 350,
		type = "immobile",
		size = 82,
		warningTime = 3.6,
		activeTime = 3.6,
		contactDmg = 30,
		delay = 10,
	},
	{
		x = 600,
		y = 300,
		type = "immobile",
		size = 93,
		warningTime = 3.6,
		activeTime = 3.6,
		contactDmg = 30,
		delay = 16,
	},
	{
		x = 450,
		y = 200,
		type = "immobile",
		size = 86,
		warningTime = 3.6,
		activeTime = 3.6,
		contactDmg = 30,
		delay = 16,
	},
	{
		x = 400,
		y = 200,
		type = "immobile",
		size = 94,
		warningTime = 3.6,
		activeTime = 3.6,
		contactDmg = 30,
		delay = 16,
	},
	{
		x = 150,
		y = 50,
		type = "immobile",
		size = 77,
		warningTime = 3.6,
		activeTime = 3.6,
		contactDmg = 30,
		delay = 16,
	},

	{
		x = 59,
		y = 452,
		type = "immobile",
		size = 84,
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
		size = 130,
		warningTime = 3.6,
		activeTime = 3.6,
		contactDmg = 30,
		delay = 19,
	},
	{
		x = 522,
		y = 449,
		type = "immobile",
		size = 70,
		warningTime = 3.6,
		activeTime = 3.6,
		contactDmg = 30,
		delay = 19,
	},
	{
		x = 321,
		y = 422,
		type = "moving",
		axis = "vertical",
		speed = 100,
		size = 70,
		warningTime = 3.6,
		activeTime = 3.6,
		contactDmg = 20,
		delay = 40,
	},
	{
		x = 581,
		y = 22,
		type = "moving",
		axis = "vertical",
		speed = 70,
		size = 150,
		warningTime = 3.6,
		activeTime = 3.6,
		contactDmg = 20,
		delay = 40,
	},
	{
		x = 1,
		y = 441,
		type = "moving",
		axis = "horizontal",
		speed = 200,
		size = 100,
		warningTime = 3.6,
		activeTime = 3.6,
		contactDmg = 20,
		delay = 40,
	},
	{
		x = 1,
		y = 141,
		type = "moving",
		axis = "horizontal",
		speed = 150,
		size = 140,
		warningTime = 3.6,
		activeTime = 3.6,
		contactDmg = 20,
		delay = 40,
	},
	{
		x = 512,
		y = 212,
		type = "immobile",
		size = 81,
		warningTime = 3.6,
		activeTime = 3.6,
		contactDmg = 30,
		delay = 88,
	},
	{
		x = 600,
		y = 616,
		type = "immobile",
		size = 88,
		warningTime = 3.6,
		activeTime = 3.6,
		contactDmg = 30,
		delay = 88,
	},
	{
		x = 128,
		y = 600,
		type = "immobile",
		size = 99,
		warningTime = 3.6,
		activeTime = 3.6,
		contactDmg = 30,
		delay = 88,
	},
	{
		x = 499,
		y = 350,
		type = "immobile",
		size = 177,
		warningTime = 3.6,
		activeTime = 3.6,
		contactDmg = 30,
		delay = 88,
	},
}

wall.append(WallSpawns, wall.horizontal_walls(-100, 300, 26, 0.1))
wall.append(WallSpawns, wall.vertical_walls(400, -100, 26.8, 0.2))
wall.append(WallSpawns, wall.vertical_walls(200, 300, 27.4, 0.4))
wall.append(WallSpawns, wall.horizontal_walls(-100, 100, 27.4, 0.2))

wall.append(WallSpawns, wall.vertical_walls(500, -100, 32, 0))
wall.append(WallSpawns, wall.horizontal_walls(-100, 300, 32.5, 0.2))
wall.append(WallSpawns, wall.vertical_walls(300, -100, 32, 0.3))

wall.append(WallSpawns, wall.moving_horizontal_walls(0, 0, 40))
wall.append(WallSpawns, wall.moving_vertical_walls(0, 0, 48))
wall.append(WallSpawns, wall.moving_horizontal_walls(120, 100, 48))

wall.append(WallSpawns, wall.horizontal_walls(100, 350, 80, 0.5))
wall.append(WallSpawns, wall.vertical_walls(400, -100, 80, 0.2))
wall.append(WallSpawns, wall.horizontal_walls(300, 600, 80.5, 0.35))

wall.append(WallSpawns, wall.moving_horizontal_walls(134, 300, 90))
wall.append(WallSpawns, wall.moving_vertical_walls(180, 20, 90))
wall.append(WallSpawns, wall.moving_horizontal_walls(120, 100, 90))

wall.append(WallSpawns, wall.moving_horizontal_walls(-100, -100, 105))
wall.append(WallSpawns, wall.moving_horizontal_walls(400, -100, 105))

-- During miniboss
wall.append(WallSpawns, wall.horizontal_walls(-100, 0, 114, 0.1))
wall.append(WallSpawns, wall.horizontal_walls(-100, 700, 114, 0.1))
wall.append(WallSpawns, wall.horizontal_walls(-100, 100, 114, 0.1))
wall.append(WallSpawns, wall.horizontal_walls(-100, 600, 114, 0.1))

wall.append(WallSpawns, wall.vertical_walls(0, -100, 130, 0.1))
wall.append(WallSpawns, wall.vertical_walls(700, -100, 130, 0.1))
wall.append(WallSpawns, wall.vertical_walls(100, -100, 130, 0.1))
wall.append(WallSpawns, wall.vertical_walls(600, -100, 130, 0.1))

wall.append(WallSpawns, wall.horizontal_walls(-100, 0, 146, 0.1))
wall.append(WallSpawns, wall.horizontal_walls(-100, 700, 146, 0.1))
wall.append(WallSpawns, wall.horizontal_walls(-100, 100, 146, 0.1))
wall.append(WallSpawns, wall.horizontal_walls(-100, 600, 146, 0.1))

wall.append(WallSpawns, wall.vertical_walls(0, -100, 162, 0.1))
wall.append(WallSpawns, wall.vertical_walls(700, -100, 162, 0.1))
wall.append(WallSpawns, wall.vertical_walls(100, -100, 162, 0.1))
wall.append(WallSpawns, wall.vertical_walls(600, -100, 162, 0.1))
