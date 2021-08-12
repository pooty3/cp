m,n = map(int,input().split())
u,l,r,d = map(int, input().split())
c = r+l+n
r = u+d+m
arr = [[None] * c for _ in range(r)]
for i in range(r):
	for j in range(c):
		arr[i][j] = '#' if (i+j)%2==0 else '.'
for i in range(m):
	s = list(input())
	for j in range(len(s)):
		arr[i+u][l+j] = s[j]
for i in range(r):
	print(''.join(arr[i]))