import sys
d = {}
tot =0
for line in sys.stdin:
	line = line.strip()
	tot += 1
	if line not in d.keys():
		d[line] = 1
	else:
		d[line] += 1
for k in sorted(d.keys()):
	print('{0} {1}'.format(k, d[k]/tot*100))