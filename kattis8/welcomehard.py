sss = "welcome to code jam"
tc = int(input())
for tttt in range(1,tc+1):
	s = input().strip()
	dp = [[None] * (len(sss)+1) for _ in range(len(s)+1)]
	dp[0][0] = 1
	for i in range(1,len(sss)+1):
		dp[0][i] = 0
	for i in range(1, len(s)+1):
		for j in range(len(sss)+1):
			dp[i][j] = dp[i-1][j]
			if j>0 and s[i-1] == sss[j-1]:
				dp[i][j] += dp[i-1][j-1]
			dp[i][j] %= 10000
	print('Case #{:d}: {:04d}'.format(tttt, dp[len(s)][len(sss)]))