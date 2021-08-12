n,d = map(int, input().split())
c = -1
ind =0
for x in input().split():
	if int(x) <= d:
		c = ind
		break
	ind += 1
print('It hadn\'t snowed this early in {0} years!'.format(c) if c != -1 else "It had never snowed this early!")