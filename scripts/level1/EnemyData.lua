-- enemy characteristics that can be configurable: total HP, speed and contactDmg

local function make_enemy(type, speed, hp, contactDmg)
	return {
		type = type,
		speed = speed,
		hp = hp,
		contactDmg = contactDmg,
	}
end

Enemies = {
	make_enemy("swarmer", 70, 40, 4),
	make_enemy("sniper", 150, 30, 0),
	make_enemy("godsip", 80, 20, 6),
	make_enemy("zomb", 70, 30, 2),
	make_enemy("monitor", 300, 10, 3),
}
