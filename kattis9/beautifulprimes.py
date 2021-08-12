tc = int(input())
for _ in range(tc):
	n = int(input())
	twos = n
	ele = 0
	while len(str((2**twos)*(11**ele))) != n:
		twos-=1
		ele+=1
	for _ in range(twos):
		print("2", end = " ")
	for _ in range(ele):
		print("11", end = " ")
	print()