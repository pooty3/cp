from math import *
tc = int(input())
for _ in range(tc):
	n = int(input())
	curX = 0
	curY = 0
	curA = 0
	for _ in range(n):	
		cmd, x = input().split()
		x = int(x)
		if cmd == "bk":
			cmd = "fd"
			x *= -1
		if cmd == "rt":
			cmd = "lt"
			x *= -1
		if cmd == "fd":
			curX += x*sin(radians(curA))
			curY += x*cos(radians(curA))
		if cmd == "lt":
			curA += x
	print(round(sqrt(curX**2 + curY**2)))
