import sys
arr = []
for _ in range(5):
	s = list(input())
	arr.append(s)
udir = [-2,1,1,2,2,1,-1,-2]
vdir = [1,2,2,1,-1,-2,-2,-1]
cc = 0
for i in range(5):
	for j in range(5):
		if arr[i][j] == '.':
			continue
		for k in range(8):
			r = i+udir[k]
			c = j+vdir[k]
			if r >-1 and r<5 and c>-1 and c<5 and arr[r][c] == 'k':
				print("invalid")
				sys.exit()
		cc +=1
print("valid" if cc== 9 else "invalid")