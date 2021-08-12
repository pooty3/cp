import sys
cs = 0
for line in sys.stdin:
	cs += 1
	e,m = map(int, line.split())
	cur = 0
	while (e != 0 or m != 0):
		cur+=1
		e +=1
		m+=1
		e%=365
		m%=687
	print('Case {0}: {1}'.format(cs, cur))