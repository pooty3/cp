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

void solve() {
	int n,k;
	cin>>n>>k;
	vi arr(n);
	REP(i, n) {
		cin>>arr[i];
	}
	vvi dp(n+1, vi(n+1, 0));
	REPL(i,1, n+1) {
		REPL(j, 1, i+1) {
			dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + (arr[i-1]==j ?1:0));
		}
	}
	int curmn = INF;
	REP(i, n+1) {
		if (dp[n][i] >=k) {
			curmn = min(curmn, n-i);
		}
	}
	if (curmn == INF) {
		cout<<-1<<"\n";
	} else {
		cout<<curmn<<"\n";
	}


}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int tc;
	cin>>tc;
	REP(i, tc) {
		solve();
	}

}