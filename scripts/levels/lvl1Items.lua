-- item type, x and y position and their time of spawning can be scripted.

local function spawn_item(type, x, y, delay)
	return {
		type = type,
		x = x,
		y = y,
		delay = delay,
	}
end

ItemSpawns = {
	spawn_item("food", 280, 350, 0.0),
	spawn_item("food", 280, 350, 4.2),
	spawn_item("food", 290, 450, 9.5),
	spawn_item("food", 50, 150, 15.0),
	spawn_item("food", 280, 150, 16.8),
	spawn_item("food", 210, 650, 22.1),
	spawn_item("food", 150, 750, 29.0),
	spawn_item("food", 50, 290, 35.2),
	spawn_item("food", 650, 90, 43.8),
	spawn_item("food", 510, 155, 49.6),
	spawn_item("food", 458, 659, 51.6),

	spawn_item("drink", 50, 150, 16.0),
	spawn_item("drink", 250, 180, 18.0),
	spawn_item("drink", 750, 250, 22.0),
	spawn_item("drink", 80, 350, 24.0),
	spawn_item("drink", 640, 390, 31.0),
	spawn_item("drink", 110, 440, 43.0),
	spawn_item("drink", 290, 560, 55.0),
	spawn_item("drink", 160, 650, 67.0),
	spawn_item("drink", 40, 150, 74.0),
	spawn_item("drink", 80, 750, 77.0),
	spawn_item("drink", 700, 240, 84.0),
	spawn_item("drink", 190, 100, 91.0),
	spawn_item("drink", 410, 490, 107.0),
	spawn_item("drink", 10, 190, 110.0),
	spawn_item("drink", 256, 166, 113.2),
	spawn_item("drink", 451, 296, 118.2),

	spawn_item("weapon", 10, 650, 11.0),
	spawn_item("weapon", 430, 390, 43.0),
	spawn_item("weapon", 50, 110, 64.0),
	spawn_item("weapon", 250, 150, 88.0),
	spawn_item("weapon", 650, 10, 102.3),
	spawn_item("weapon", 111, 56, 129.8),
}
