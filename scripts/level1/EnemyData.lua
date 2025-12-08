-- enemy characteristics that can be configurable: total HP and speed

local function make_enemy(type, speed, hp)
	return {
		type = type,
		speed = speed,
		hp = hp,
	}
end

Enemies = {
	make_enemy("swarmer", 120, 40),
	make_enemy("sniper", 150, 30),
	make_enemy("godsip", 80, 20),
	make_enemy("zomb", 70, 30),
	make_enemy("monitor", 300, 10),
}
