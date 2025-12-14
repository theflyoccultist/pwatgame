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
	make_enemy("swarmer", 120, 60, 12),
	make_enemy("sniper", 250, 30, 0),
	make_enemy("godsip", 19, 70, 20),
	make_enemy("zomb", 300, 40, 5),
	make_enemy("monitor", 300, 10, 5),
}
