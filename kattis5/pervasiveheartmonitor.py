import sys
def isfloat(potential_float):
    try:
        float(potential_float)
        return True
    except ValueError:
        return False

for line in sys.stdin:
	tok = line.split()
	name = []
	tot =0
	c =0
	for t in tok:
		if not isfloat(t):
			name.append(t)
		else:
			tot += float(t)
			c+=1
	print('{0} {1}'.format(tot/c, ' '.join(name)))