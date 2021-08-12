p, d = map(int, input().split())
arr = [[0,0] for i in range(d)]
for zz in range(0,p):
	u,a,b = map(int, input().split())
	u-=1
	arr[u][0]+=a
	arr[u][1] +=b
tot =0
wa =0
wb=0
for i in range(d):
	a,b = arr[i]
	mn = (a+b)//2 +1
	tot += (a+b)
	aa = a if a<mn else (a-mn)
	bb = b if b<mn else (b-mn)
	print('{0} {1} {2}'.format('A' if b<mn else 'B', aa,bb))
	wa += aa
	wb+=bb
print(abs(wa-wb)/tot)