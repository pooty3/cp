tc = int(input())
for _ in range(tc):
	p = 1000000007
	n = int(input()) -1
	val = pow(9,n,p)
	print((val*8)%p)