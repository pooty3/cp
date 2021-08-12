arr = [['*' for _ in range(11)] for _ in range(11)]
for i in range(2, 9):
	s = input().strip().center(11, '*')
	arr[i] = list(s)
vd = [0,0,1,-1]
hd = [1,-1,0,0]
tot = 0
for i in range(11):
	for j in range(11):
		if arr[i][j] != 'o':
			continue
		for k in range(4):
			if (arr[i+vd[k]][j+hd[k]] == 'o' and arr[i+vd[k]*2][j+hd[k]*2] == '.'):
				tot += 1
print(tot)