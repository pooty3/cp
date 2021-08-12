def inside(r,x,y):
	x1,y1,x2,y2 = r
	return x in range(x1,x2+1) and y in range(y1, y2+1)
def insideC(c,x,y):
	x1,y1,r = c
	return abs(x1-x)**2 + abs(y1-y)**2 <= r**2
t = int(input())
cir= []
rect = []
for _ in range(t):
	ss = input().split()
	if ss[0] == "rectangle":
		rect.append(list(map(int,[ss[1], ss[2], ss[3], ss[4]])))
	else:
		cir.append(list(map(int, [ss[1],ss[2],ss[3]])))
n = int(input())
for _ in range(n):
	x,y = map(int, input().split())
	print(sum(map(lambda re: inside(re,x,y) ,rect))+ sum(map(lambda c: insideC(c,x,y) ,cir)))