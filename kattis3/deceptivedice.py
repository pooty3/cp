n,k = map(int, input().split())
curE = (n+1)/2
for _ in range(k-1):
	newE = 0
	for i in range(1,n+1):
		newE += max(i, curE)
	curE = newE/n
print(curE)
