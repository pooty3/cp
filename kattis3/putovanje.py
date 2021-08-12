import sys
n,c = map(int, input().split())
arr = list(map(int, input().split()))
curb = 0
for i in range(n):
	curc = c
	cc =0
	for j in range(i, n):
		if curc >= arr[j]:
			cc+=1
			curc -= arr[j]
	curb = max(curb,cc)
print(curb)

	