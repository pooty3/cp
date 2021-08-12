tc =int(input())
for _ in range(tc):
	x1,y1,x2,y2 = map(int, input().split())
	dx = abs(x1-x2)
	dy = abs(y1-y2)
	print(dx+dy + abs(dx-dy) - (1 if abs(dx-dy)%2 ==1 else 0))