#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define SORT(arr) sort(arr.begin(), arr.end())
#define LSOne(S) ((S)&-(S))
#define M_PI 3.1415926535897932384
#define INF 999999999
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	string a,b;
	cin>>a>>b;
	vvi dp(n+1, vi(m+1, -1));
	dp[0][0] = 0;
	REPL(i, 1,m+1) {
		dp[0][i] = -1;
	}
	REPL(i, 1, n+1) {
		dp[i][0] = -1;
		REPL(j, 1, m+1) {
			if (a[i-1]==b[j-1]) {
				dp[i][j] = 2+max(dp[i-1][j-1], 0);
				dp[i][j] = max(dp[i][j], dp[i][j-1]-1);
				dp[i][j] = max(dp[i][j], dp[i-1][j]-1);
			} else {
				dp[i][j] = max(-2, dp[i][j-1]-1);
				dp[i][j] = max(dp[i][j], dp[i-1][j]-1);
			}
		}
	}
	int curmx = 0;
	REP(i, n+1) {
		REP(j, m+1) {
			curmx = max(curmx, dp[i][j]);
		}
	}cout<<curmx<<"\n";
}