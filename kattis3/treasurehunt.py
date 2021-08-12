import sys
r,c = map(int,input().split())
arr =[]
for _ in range(r):
	arr.append(list(input()))
cur = (0,0)
for i in range(r*c +2):
	x,y = cur
	if x not in range(r) or y not in range(c):
		print("Out")
		sys.exit()
	if arr[x][y] == 'N':
		x -=1
	elif arr[x][y] == 'S':
		x+=1
	elif arr[x][y] == 'W':
		y -=1
	elif arr[x][y] == 'E':
		y +=1
	elif arr[x][y] == 'T':
		print(i)
		sys.exit()
	cur = (x,y)
print("Lost")

