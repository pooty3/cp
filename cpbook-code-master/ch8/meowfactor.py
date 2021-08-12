n = int(input())
cur = 1
i = 1
while (i**9) <=n:
	if n%(i**9) ==0:
		cur = i
	i +=1
print(cur)