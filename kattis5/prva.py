r,c = map(int, input().split())
strs = ["" for x in range(r+1)]
for i in range(r):
	strs[i] = input() + "#"
strs[r] = '#' * (c+1)
curbest = "z"*50
for i in range(r):
	prev= ""
	for j in range(c+1):
		if strs[i][j] == '#':
			if len(prev)>=2:
				curbest = min(prev, curbest)
			prev = ""
		else:
			prev += strs[i][j]
for i in range(c):
	prev= ""
	for j in range(r+1):
		if strs[j][i] == '#':
			if len(prev)>=2:
				curbest = min(prev, curbest)
			prev = ""
		else:
			prev += strs[j][i]
print(curbest)