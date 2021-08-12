#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define SORT(arr) sort(arr.begin(), arr.end())
#define LSOne(S) ((S)&-(S))
#define M_PI 3.1415926535897932384
#define INF 999999
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

int mindist(vvi &dp, vvi &disarr, int u, int mask) {
	if (mask == 0) {
		return disarr[u][0];
	}
	if (dp[u][mask]==-1) {
		int mn = INF;
		int m = mask;
		while (m) {
			int l = LSOne(m);
			int v = __builtin_ctz(l);
			mn = min(mn, disarr[u][v] + mindist(dp, disarr, v, mask^l));
			m -= l;
		}
		dp[u][mask] = mn;
	}
	return dp[u][mask];
}

void solve() {
	int x,y;
	cin>>x>>y;
	int sx,sy;
	cin>>sx>>sy;
	vii pos;
	pos.push_back({sx,sy});
	int n;
	cin>>n;
	REP(i, n) {
		cin>>x>>y;
		pos.push_back({x,y});
	}
	vvi disarr(n+1, vi(n+1, 0));
	REP(i, n+1) {
		REP(j, n+1) {
			disarr[i][j] = abs(pos[i].first - pos[j].first)
			+abs(pos[i].second - pos[j].second);
		}
	}
	vvi dp(n+1, vi(1<<(n+1),-1));
	cout<<mindist(dp, disarr, 0, (1<<(n+1))-1)<<"\n";

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