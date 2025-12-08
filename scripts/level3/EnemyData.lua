-- enemy characteristics that can be configurable: total HP and speed

local function make_enemy(type, speed, hp)
	return {
		type = type,
		speed = speed,
		hp = hp,
	}
end

Enemies = {
	make_enemy("swarmer", 120, 60),
	make_enemy("sniper", 250, 30),
	make_enemy("godsip", 19, 70),
	make_enemy("zomb", 300, 40),
	make_enemy("monitor", 300, 10),
}
