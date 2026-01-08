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
	make_enemy("fractal", 30, 300, 2),
	make_enemy("godsip", 40, 80, 10),
	make_enemy("miku", 180, 300, 0),
	make_enemy("monitor", 158, 40, 4),
	make_enemy("sniper", 180, 40, 0),
	make_enemy("zomb", 34, 40, 3),
}
