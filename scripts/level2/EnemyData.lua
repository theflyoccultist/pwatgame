-- enemy characteristics that can be configurable: total HP and speed

local function make_enemy(type, speed, hp)
	return {
		type = type,
		speed = speed,
		hp = hp,
	}
end

Enemies = {
	make_enemy("swarmer", 230, 20),
	make_enemy("sniper", 180, 40),
	make_enemy("godsip", 40, 80),
	make_enemy("zomb", 34, 40),
	make_enemy("monitor", 300, 40),
}
