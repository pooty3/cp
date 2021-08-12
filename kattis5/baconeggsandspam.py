from collections import OrderedDict
while True:
	n = int(input())
	if n == 0 : 
		break
	d = {}
	for sss in range(n):
		ss = input().split()
		for s in ss[1:]:
			if s in d:
				d[s].add(ss[0])
			else:
				d[s] = {ss[0]}
	for k in sorted(d):
		print(k,end=" ")
		for val in sorted(d[k]):
			print(val, end= " ")
		print("")
	print()