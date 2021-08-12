import sys
n = int(input())
arr = []
for _ in range(n):
	arr.append(int(input()))
arr.sort(reverse = True)
cur = 1
for i in arr:
	if i<cur:
		print(cur-1)
		sys.exit()
	cur+=1
print(len(arr))