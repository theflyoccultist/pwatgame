-- miniboss characteristics that can be configurable: total HP and speed

local function make_miniboss(type, speed, hp)
	return {
		type = type,
		speed = speed,
		hp = hp,
	}
end

MiniBosses = {
	make_miniboss("windows", 200, 3500),
	make_miniboss("lisp", 80, 1300),
	make_miniboss("java", 150, 4850),
	make_miniboss("rust", 150, 8000),
}
