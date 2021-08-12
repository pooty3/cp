import sys
for line in sys.stdin:
	m,p,l,e,r,s,n = map(int, line.split())
	for _ in range(n):
		nl = m*e
		np = l//r
		nm = p//s
		m =nm
		p = np
		l= nl
	print(m)