tc = int(input())
sss = "simon says "
for _ in range(tc):
	s = input()
	if s.startswith(sss):
		print(s[len(sss):])
	else:
		print()