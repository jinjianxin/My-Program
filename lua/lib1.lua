--run this programe  dofile("lib1.lua")

function norm (x, y)
	local n2 = x^2 + y^2
	return math.sqrt(n2)
end
		 
function twice (x)
	return 2*x
end

--  此处x为全部变量
x=10
local i =1

while i<=x do
	local x = i*2 -- 此处x为局部变量
	print(x)
	i=i+1
end

--[[
--多行注释
--尽可能的使用局部变量，因为访问局部变量要比访问全局变量快
--]]
--
if i>20 then 
	local x
	x=20
	print(x+2)
else
	print(x)
end

print(x)

--  if语句的三种形式
if i>10 then
	print()
end

if i==10 then
	print()
else
	print()
end

if i==10 then
	print()
elseif i>10 then
	print()
elseif i>11 then
	print()
else
	print()
end

-- while 循环
while i<10 do
	print()
end

-- for循环
for var=1,10 do 
	print(var)
end

local found = nil
for i=1,10 do
	if i == 5 then
		found = i
		break;
	end
end

print("found="..found)


local a1 = "hello"
local a2 = "world"
print(a1..a2)  --  ..相当于C++中的+运算符  

-- 返回多个值
s, e = string.find("hello Lua users", "Lua")
print(s,e)

function mainnum(a)
	local mi =1;
	local m = a[mi]
	for i,val in ipairs(a) do
		if val >m then
			mi = i
			m = val
		end
	end
	return m ,mi
end

print(mainnum({8,24,36,2,14,78,25}))
