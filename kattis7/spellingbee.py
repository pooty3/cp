s = input()
n = int(input())
for _ in range(n):
	ss = input()
	if s[0] in ss and len(ss)>=4 and len([c for c in ss if c not in list(s)]) == 0:
		print(ss)