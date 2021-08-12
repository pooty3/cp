import sys
for line in sys.stdin:
	print(sum(list(map(int, line.split())))//2)