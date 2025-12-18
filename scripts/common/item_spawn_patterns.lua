local I = {}

function I.append(dst, src)
	for _, e in ipairs(src) do
		dst[#dst + 1] = e
	end
end

function I.bulk_drink_spawn(count, delay, type, hpBonus)
	local t = {}

	for _ = 1, count do
		local x = math.random(0, 750)
		local y = math.random(0, 750)

		t[#t + 1] = {
			x = x,
			y = y,
			delay = delay,
			type = type,
			hpBonus = hpBonus,
		}
	end

	return t
end

function I.zoned_drink_spawn(rows, cols, delay, type, start_x, start_y, dx, dy, hpBonus)
	local t = {}

	for r = 1, rows do
		local x = start_x + r * dx
		local y = start_y

		for _ = 1, cols do
			y = y + dy

			t[#t + 1] = {
				x = x,
				y = y,
				delay = delay,
				type = type,
				hpBonus = hpBonus or 10,
			}
		end
	end

	return t
end

function I.bulk_food_spawn(count, delay, type, ammoBonus)
	local t = {}

	for _ = 1, count do
		local x = math.random(0, 750)
		local y = math.random(0, 750)

		t[#t + 1] = {
			x = x,
			y = y,
			delay = delay,
			type = type,
			ammoBonus = ammoBonus,
		}
	end

	return t
end

return I
