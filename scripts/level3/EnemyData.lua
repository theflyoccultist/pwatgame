-- enemy characteristics that can be configurable: total HP and speed

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
	make_enemy("godsip", 80, 65, 150, 10),
	make_enemy("duo", 0, 89, 220, 4),
	make_enemy("clank", 15, 81, 100, 2),
	make_enemy("threademitter", 20, 59, 30, 0),
}
