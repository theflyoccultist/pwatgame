-- enemy characteristics that can be configurable: total HP and speed

local function make_enemy(type, speed, hp, contactDmg)
	return {
		type = type,
		speed = speed,
		hp = hp,
		contactDmg = contactDmg,
	}
end

Enemies = {
	make_enemy("swarmer", 120, 60, 8),
	make_enemy("sniper", 150, 30, 0),
	make_enemy("godsip", 300, 70, 2),
	make_enemy("zomb", 70, 40, 7),
	make_enemy("monitor", 300, 10, 10),
	make_enemy("constrainer", 420, 1000, 80),
}
