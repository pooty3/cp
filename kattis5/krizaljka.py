s1, s2 = input().split()
c = ''
for cc in s1:
	if s2.find(cc) != -1:
		c = cc
		break
arr = [["." for _ in range(len(s1))] for _ in range(len(s2))]
for i in range(len(s1)):
	arr[s2.find(c)][i] = s1[i]
for i in range(len(s2)):
	arr[i][s1.find(c)] = s2[i]
for i in range(len(s2)):
	print(''.join(arr[i]))