-- enemy characteristics that can be configurable: total HP, speed and contactDmg

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
	make_enemy("swarmer", 70, 69, 40, 4),
	make_enemy("sniper", 150, 61, 30, 0),
	make_enemy("godsip", 80, 75, 20, 6),
	make_enemy("zomb", 70, 63, 30, 2),
	make_enemy("monitor", 300, 80, 10, 3),
}
