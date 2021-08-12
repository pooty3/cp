from collections import *
s = input().strip()
t = input().strip()
for ch in(Counter(t) - Counter(s)).keys():
	print(ch, end= )
