tc = int(input())
for ccc in range(1, tc+1):
	_ = int(input())
	arr = input().split()
	r = []
	b = []
	for s in arr:
		if s[-1] == 'R':
			r.append(int(s[:-1]))
		else:
			b.append(int(s[:-1]))
	r.sort(reverse = True)
	b.sort(reverse = True)
	cur = 0
	for i in range(min(len(r), len(b))):
		cur += r[i]+b[i] -2
	print('Case #{0}: {1}'.format(ccc, cur))
