p,t = map(int, input().split())
count = 0
for _ in range(p):
	able = True
	for _ in range(t):
		s = input()
		able&= s[1:] == s[1:].lower()
	count += able
print(count)