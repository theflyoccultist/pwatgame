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
	make_enemy("godsip", 80, 150, 10),
	make_enemy("duo", 0, 220, 4),
	make_enemy("clank", 15, 100, 2),
	make_enemy("threademitter", 20, 30, 0),
}
