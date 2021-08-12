from queue import *
udir = [0,0,-1,1]
vdir = [1,-1,0,0]
n = 0
def bfs(arr, num, sarr, coloring):
	q = Queue()
	vis = [[False for _ in range(n)] for _ in range(n)]
	for x in sarr:
		q.put(x)
		vis[x[0]][x[1]] = True
	co = 0
	while not q.empty():
		co += 1
		r, c = q.get()
		for i in range(4):
			nr = r + udir[i]
			nc = c + vdir[i]
			if nr in range(n) and nc in range(n) and not vis[nr][nc] and arr[nr][nc] == num:
				vis[nr][nc] = True
				q.put((nr,nc))
				if coloring:
					sarr.append((nr,nc))
	return co

tc = int(input())
for _ in range(tc):
	n = int(input())
	arr = []
	for _ in range(n):
		arr.append(list(map(int,list(input()))))
	marr = [0 for _ in range(6)]
	sarr = [(0,0)]
	bfs(arr, arr[0][0], sarr, True)
	while len(sarr) != n*n:
		curmx = (0, 0)
		for i in range(1,7):
			curmx = max(curmx, (bfs(arr, i, sarr, False),-i))
		bfs(arr, -curmx[1], sarr, True)
		marr[-curmx[1]-1] +=1
	print(sum(marr))
	print(' '.join(map(str, marr)))
