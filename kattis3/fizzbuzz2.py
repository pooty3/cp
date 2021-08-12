n,m = map(int, input().split())
curb = (0, -n-1)
for i in range(n):
	toks = input().split()
	c = 0
	for j in range(m):
		cur = "fizzbuzz" if (j+1)%15==0 else "fizz" if (j+1)%3 ==0 else "buzz" if (j+1)%5 ==0 else str(j+1) 
		c += (cur == toks[j])
	curb = max(curb, (c, -i))
print(-curb[1]+1)