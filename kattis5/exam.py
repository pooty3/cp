k = int(input())
s1 = input()
s2= input()
for i in range(len(s1)):
	k -= s1[i]==s2[i]
print(len(s1)-abs(k))