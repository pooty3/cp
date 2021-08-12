import math
while True:
	n = int(input())
	if n==0:
		break
	mx = 1e10
	mn = 1
	div = []
	for _ in range(n):
		ss = input().split()
		x = int(ss[2])
		if ss[0] == "less":
			mx = min(mx, x-1)
		if ss[0] == "greater":
			mn = max(mn, x+1)
		if ss[0] == "divisible":
			div.append(x)
	if mx == 1e10:
		print("infinite")
	else:
		arr = [i for i in range(mn, mx+1) if all(i%x==0 for x in div)]
		if len(arr)==0:
			print("none")
		else:
			print(' '.join(map(str, arr)))