s = {"ee", "aa", "oo", "yy", "ii", "uu"}
while True:
	n = int(input())
	if n ==0:
		break
	best = ""
	amt = -1
	for _ in range(n):
		w = input().strip()
		nn = sum(map(lambda x: w.count(x), s))
		if nn>amt:
			amt = nn
			best = w
	print(best)