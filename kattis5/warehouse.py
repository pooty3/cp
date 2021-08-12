tc = int(input())
for _ in range(tc):
	d = {}
	k = int(input())
	for _ in range(k):
		s1, s2 = input().split()
		if s1 in d.keys():
			d[s1] += int(s2)
		else:
			d[s1] = int(s2)
	arr = []
	for (k, v) in d.items():
		arr.append((-v, k))
	arr.sort()
	print(len(arr))
	for (v, k) in arr:
		print('{0} {1}'.format(k,-v))