tc = int(input())
for _ in range(tc):
	n1 = int(input())
	arr1 = list(map(int,input().split()))
	n2 = int(input())
	arr2 = list(map(int,input().split()))
	arr3 = [0 for i in range(n1+n2+1)]
	for i in range(n1+1):
		for j in range(n2+1):
			arr3[i+j] += arr1[i] * arr2[j]
	print(n1 + n2)
	print(' '.join(map(str, arr3)))
