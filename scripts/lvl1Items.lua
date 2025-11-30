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
	spawn_item("food", 250, 350, 1.0),
	spawn_item("food", 280, 350, 4.0),
	spawn_item("food", 290, 450, 9.5),
	spawn_item("food", 280, 150, 16.8),
	spawn_item("food", 210, 650, 22.1),
	spawn_item("food", 150, 750, 29.0),
	spawn_item("food", 50, 150, 15.0),
	spawn_item("drink", 50, 150, 16.0),
	spawn_item("drink", 50, 180, 18.0),
	spawn_item("drink", 50, 250, 22.0),
	spawn_item("drink", 50, 350, 24.0),
	spawn_item("drink", 50, 390, 31.0),
	spawn_item("drink", 50, 440, 43.0),
	spawn_item("drink", 50, 560, 55.0),
	spawn_item("drink", 50, 650, 67.0),
	spawn_item("weapon", 10, 650, 5.0),
	spawn_item("weapon", 10, 650, 11.0),
	spawn_item("weapon", 10, 650, 19.0),
	spawn_item("weapon", 10, 650, 43.0),
	spawn_item("weapon", 10, 650, 55.0),
	spawn_item("weapon", 10, 650, 64.0),
	spawn_item("weapon", 10, 650, 88.0),
}
