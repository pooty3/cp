tc = int(input())
for _ in range(tc):
	toks = input().split()
	arr = set()
	while True:
		ss = input().split()
		if len(ss) == 3:
			arr.add(ss[2])
		else:
			break
	print(' '.join(filter(lambda x: x not in arr, toks)))
