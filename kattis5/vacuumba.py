from math import *
tc = int(input())
for _ in range(tc):
	n = int(input())
	curx =0
	cury =0
	curd =90
	for _ in range(n):
		deg, d = map(float, input().split())
		curd += deg
		curx += d * cos(radians(curd))
		cury += d * sin(radians(curd))
	print('{0} {1}'.format(curx,cury))
