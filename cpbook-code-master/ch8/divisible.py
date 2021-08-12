tc = int(input())
for _ in range(tc):
	d, n = map(int, input().split())
	arr = list(map(int, input().split()))
	farr= {0:0}
	cur =0
	for i in arr:
		cur += i
		cur %= d
		if cur not in farr.keys():
			farr[cur] = 1
		else:
			farr[cur]+=1
	tot =0
	cur = 0
	for i in arr:
		tot += farr[cur]
		cur += i
		cur %= d
		farr[cur]-=1
	print(tot)