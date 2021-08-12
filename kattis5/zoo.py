cc = 0
while True:
	cc += 1
	n = int(input())
	if n ==0: 
		break
	d = {}
	for _ in range(n):
		ss = (input().split())[-1].lower()
		if ss in d:
			d[ss] += 1
		else:
			d[ss] = 1

	print('List {0}:'.format(cc))
	for k in sorted(d):
		print('{0} | {1}'. format(k, d[k]))