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
int md = 1e9 + 7;

void solve() {
	int n,k;
	cin>>n>>k;
	vvi dp(k+1, vi(n, -1));
	if (n==1) {
		cout<<(k==1? 1:2)<<"\n";return;
	}
	REP(i, n) {
		dp[1][i] = 1;
	}
	REPL(i,2, k+1) {
		REP(j, n) {
			dp[i][j] = 0;
			if (j==0) {
				dp[i][j] = 1 + dp[i-1][n-2];
			} else if (j == n-1) {
				dp[i][j] = 1 + dp[i][j-1];
			} else {
				dp[i][j] = dp[i][j-1] + dp[i-1][n-j-2];
			}
			dp[i][j] %=md;
		}
	}
	cout<<dp[k][n-1]<<"\n";

}

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	int tc;
	cin>>tc;
	REP(i, tc) {
		solve();
	}

}