-- enemy characteristics that can be configurable: total HP and speed

local function make_enemy(type, speed, hp)
	return {
		type = type,
		speed = speed,
		hp = hp,
	}
end

Enemies = {
	make_enemy("swarmer", 150, 70),
	make_enemy("sniper", 200, 40),
	make_enemy("godsip", 100, 80),
	make_enemy("zomb", 90, 40),
	make_enemy("monitor", 300, 40),
}
