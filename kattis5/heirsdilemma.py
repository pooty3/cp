from collections import Counter
def able(x):
	s = str(x)
	if len(s) != len(Counter(s)) or s.count("0") != 0:
		return 0
	for c in s:
		if x%(int(c)) != 0:
			return 0
	return 1
l,h = map(int, input().split())

print(sum(map(lambda x: able(x), range(l, h+1))))