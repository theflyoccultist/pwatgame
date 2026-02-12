local M = {}

function M.append(dst, src)
	for _, e in ipairs(src) do
		dst[#dst + 1] = e
	end
end

function M.monitor_circle(delay)
	local t = {
		{ x = -320, y = 320, delay = delay, type = "monitor" },
		{ x = -250, y = 250, delay = delay + 1, type = "monitor" },
		{ x = -60, y = 600, delay = delay + 2, type = "monitor" },
		{ x = -500, y = 500, delay = delay + 3, type = "monitor" },
		{ x = -100, y = 100, delay = delay + 4, type = "monitor" },
		{ x = -480, y = 480, delay = delay + 5, type = "monitor" },
	}

	return t
end

function M.godsip_cardinal(delay)
	local t = {
		{ x = math.random(0, 730), y = math.random(0, 730), delay = delay, type = "godsip" },
		{ x = math.random(0, 730), y = math.random(0, 730), delay = delay, type = "godsip" },
		{ x = math.random(0, 730), y = math.random(0, 730), delay = delay, type = "godsip" },
		{ x = math.random(0, 730), y = math.random(0, 730), delay = delay, type = "godsip" },
	}

	return t
end

function M.swarm(type, count, start_x, start_y, dx, dy, delay, delay_step)
	local t = {}
	local x, y = start_x, start_y
	delay_step = delay_step or 0

	for _ = 1, count do
		x = x + dx
		y = y + dy
		delay = delay + delay_step

		t[#t + 1] = {
			x = x,
			y = y,
			delay = delay,
			type = type,
		}
	end

	return t
end

function M.zomb_chaos(type, count, delay, delay_step)
	local t = {}
	delay_step = delay_step or 0

	for _ = 1, count do
		local x = math.random(0, 730)
		local y = math.random(0, 730)
		delay = delay + delay_step

		t[#t + 1] = {
			x = x,
			y = y,
			delay = delay,
			type = type,
		}
	end

	return t
end

return M
