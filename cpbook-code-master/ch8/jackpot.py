from math import *
tc = int(input())
for _ in range(tc):
	n = int(input())
	arr = map(int, input().split())
	cur = 1
	for i in arr:
		cur = cur*i//gcd(i,cur)
		if cur > 1e9:
			break
	print(cur if cur <= 1e9 else "More than a billion.")