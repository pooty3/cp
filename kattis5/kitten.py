k = int(input())
arr = [-1 for i in range(101)]
while True:
	val = [int(i) for i in input().split()]
	if len(val) == 1:
		break
	for i in range(1, len(val)):
		arr[val[i]] = val[0]
while k != -1:
	print(k, end=" ")
	k = arr[k]