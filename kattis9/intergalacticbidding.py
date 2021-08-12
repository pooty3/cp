n,s = map(int,input().split())
amt = []
for _ in range(n):
	nme, am = input().split()
	amt.append((int(am), nme))
amt.sort(reverse = True)
final = []
for (am, nme) in amt:
	if (am<=s):
		final.append(nme)
		s -= am
if s != 0:
	print(0)
else:
	print(len(final))
	print('\n'.join(final))
