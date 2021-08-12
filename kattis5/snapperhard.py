tc = int(input())
for j in range(1, tc+1):
	n,k = map(int, input().split())
	print('Case #{0}: {1}'.format(j, "ON" if all(map(lambda x: k&(1<<x), range(0, n))) else "OFF"))