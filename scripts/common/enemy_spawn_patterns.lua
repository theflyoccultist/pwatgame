local M = {}

function M.append(dst, src)
	for _, e in ipairs(src) do
		dst[#dst + 1] = e
	end
end

function M.monitor_circle(delay)
	local t = {}
	local x, y = 320, 320

	for i = 1, 6 do
		t[#t + 1] = {
			x = x,
			y = y,
			delay = delay + i,
			type = "monitor",
		}
	end

	return t
end

function M.godsip_cardinal(delay)
	local t = {
		{ x = 0, y = 0, delay = delay, type = "godsip" },
		{ x = 730, y = 0, delay = delay, type = "godsip" },
		{ x = 0, y = 730, delay = delay, type = "godsip" },
		{ x = 730, y = 730, delay = delay, type = "godsip" },
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

function M.zomb_chaos(count, delay, delay_step)
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
			type = "zomb",
		}
	end

	return t
end

return M
