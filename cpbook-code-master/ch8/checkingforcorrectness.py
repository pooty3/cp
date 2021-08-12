import sys
for line in sys.stdin:
	s1,s2,s3 = line.split()
	s1 = int(s1)
	s3 = int(s3)
	if s2 == '*':
		print((s1*s3)%10000)
	if s2 == '+':
		print((s1+s3)%10000)
	if s2 == '^':
		print(pow(s1,s3,10000)) 