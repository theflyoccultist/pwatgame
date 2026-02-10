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
	make_enemy("swarmer", 120, 70, 60, 8),
	make_enemy("sniper", 150, 61, 30, 0),
	make_enemy("godsip", 100, 64, 70, 4),
	make_enemy("zomb", 70, 75, 40, 7),
	make_enemy("constrainer", 420, 55, 10, 20),
	make_enemy("wall", 0, 100, 100000, 50),
	make_enemy("wallmove", 100, 100, 100000, 50),
}
