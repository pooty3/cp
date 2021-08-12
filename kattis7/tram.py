def dist(a, arr):
	return sum(map(lambda x: abs(x[1]-a-x[0])**2, arr))


n = int(input())
arr = []
for _ in range(n):
	arr.append(list(map(int, input().split())))
mn = -1000000
mx = 1000000
while(mx-mn > 0.00001):
	d = (mx-mn)/3
	if dist(mn+d, arr)<dist(mx-d, arr):
		mx = mx-d
	else:
		mn = mn+d
print('%.5f'%mx)

