-- miniboss characteristics that can be configurable: total HP and speed

local function make_miniboss(type, speed, hp)
	return {
		type = type,
		speed = speed,
		hp = hp,
	}
end

MiniBosses = {
	make_miniboss("windows", 200, 1000),
	make_miniboss("lisp", 150, 100),
	make_miniboss("java", 150, 100),
	make_miniboss("rust", 150, 100),
}
