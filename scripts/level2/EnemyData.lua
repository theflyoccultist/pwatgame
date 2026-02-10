-- enemy characteristics that can be configurable: total HP and speed

local function make_enemy(type, speed, size, hp, contactDmg)
	return {
		type = type,
		speed = speed,
		size = size,
		hp = hp,
		contactDmg = contactDmg,
	}
end

Enemies = {
	make_enemy("fractal", 30, 87, 300, 2),
	make_enemy("godsip", 40, 74, 80, 10),
	make_enemy("miku", 180, 83, 100, 0),
	make_enemy("monitor", 158, 62, 40, 4),
	make_enemy("sniper", 180, 65, 40, 0),
	make_enemy("zomb", 34, 70, 40, 3),
}
