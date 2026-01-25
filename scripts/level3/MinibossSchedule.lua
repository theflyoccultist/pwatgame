local timings = require("common.timings")

local function spawn_miniboss(type, delay)
	return {
		type = type,
		delay = delay,
	}
end

MinibossSpawns = {
	spawn_miniboss("java", timings.lvl3minibossDelay),
	-- spawn_miniboss("java", 86.0),
}
