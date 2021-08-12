tc = int(input())
for _ in range(tc):
	x,y = map(float, input().split())
	n = int(input())
	able = False
	for _ in range(n):
		x1,y1 = map(float, input().split())
		if abs(x1-x)**2 + abs(y1-y)**2 <= 8**2:
			able = True
	print("light a candle" if able else "curse the darkness")