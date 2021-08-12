import sys
from datetime import datetime
for line in sys.stdin:
	m,d,y, t1, t2 = line.split()
	tt1 = datetime.strptime(t2, '%H:%M') - datetime.strptime(t1, '%H:%M')
	print('{0} {1} {2} {3} hours {4} minutes'.format(m,d,y,tt1.seconds//3600, tt1.seconds//60%60))