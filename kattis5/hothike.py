n = int(input())
curb = (1000, 0)
ss = list(map(int, input().split())
for i in range(n-2):
	curb = min(curb, (max(ss[i], ss[i+2]), i+1))
print('{0} {1}'.format(curb[1], curb[0]))