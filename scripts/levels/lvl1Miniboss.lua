-- miniboss type, and time of spawning will be scripted here.
-- It is possible to spawn several minibosses, but
-- the player defeating one of them will end the level automatically.
-- it will spawn at the center of the map.

local function spawn_miniboss(type, delay)
	return {
		type = type,
		delay = delay,
	}
end

MinibossSpawns = {
	spawn_miniboss("windows", 128.0),
}
