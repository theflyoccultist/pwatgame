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
	make_enemy("fractal", 30, 87, 500, 2),
	make_enemy("duo", 0, 89, 500, 4),
	make_enemy("swarmer", 180, 70, 60, 14),
	make_enemy("sniper", 150, 61, 30, 0),
	make_enemy("godsip", 100, 64, 70, 4),
	make_enemy("constrainer", 420, 55, 10, 12),
}
