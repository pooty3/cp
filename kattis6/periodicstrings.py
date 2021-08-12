s = input()
for i in range(1, len(s)+1):
	if len(s)%i != 0:
		continue
	ss = [s[j:i+j] for j in range(0, len(s), i)]
	able = True
	for j in range(1, len(ss)):
		if not (ss[j-1][:-1] == ss[j][1:] and ss[j-1][-1] == ss[j][0]):
			able = False
			break
	if able:
		print(i)
		break