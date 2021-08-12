def addedge(u, v, adj):
	if u not in adj.keys():
		adj[u] = set()
	adj[u].add(v)
from queue import *
n = int(input())
adj = {}
for _ in range(n):
	arr = input().split()
	for i in range(1, len(arr)):
		addedge(arr[0], arr[i], adj)
		addedge(arr[i], arr[0], adj)
s,d = input().split()
par = {s: ""}
q = Queue()
q.put(s)

while not q.empty():
	u = q.get()
	if u not in adj.keys():
		continue
	for v in filter(lambda x: x not in par.keys(), adj[u]):
		par[v] = u
		q.put(v)
if d not in par.keys():
	print("no route found")
else:
	arr = []
	cur = d
	while(cur != ""):
		arr.append(cur)
		cur = par[cur]
	print(' '.join(arr[::-1]))