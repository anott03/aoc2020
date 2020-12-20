#!/usr/bin/lua
local filepath = "/home/amitav/dev/advent-of-code-2020/day9/input.prod"

function table.slice(tbl, first, last, step)
  local sliced = {}

  for i = first or 1, last or #tbl, step or 1 do
    sliced[#sliced+1] = tbl[i]
  end

  return sliced
end

local function isSum(val, prevlines)
  for _, val1 in pairs(prevlines) do
    for _, val2 in pairs(prevlines) do
      if tonumber(val1) + tonumber(val2) == tonumber(val) then
        return true
      end
    end
  end

  return false
end

local function findSum(val, lines)
  local sum = 0
  local idx = 1
  local prev_idx = 1
  local max
  local min
  while not (sum == val) do
    local n = tonumber(lines[idx])
    sum = sum + n

    if max then
      if n > max then max = n end
    else
      max = n
    end

    if min then
      if n < min then min = n end
    else
      min = n
    end

    if (sum > val) then
      sum = 0;
      max = nil
      min = nil
      idx = prev_idx + 1
      prev_idx = prev_idx + 1
    end
    idx = idx + 1
  end
  return max + min
end

local lines = {}
for line in io.lines(filepath) do
  lines[#lines + 1] = line
end

local n;
for i, val in pairs(lines) do
  if i > 25 then
    if not isSum(val, table.slice(lines, i - 25, i - 1)) then
      n = tonumber(val)
      print(val)
      break
    end
  end
end

print(findSum(n, lines))
