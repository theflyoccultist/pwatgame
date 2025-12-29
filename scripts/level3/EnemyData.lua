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
	make_enemy("godsip", 150, 70, 20),
	make_enemy("duo", 0, 100, 4),
	make_enemy("clank", 15, 100, 2),
}
