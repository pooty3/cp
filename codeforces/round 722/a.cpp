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
vvi adj;
vector<vll> arr;
vvll dp;
ll dos(int p, int cur, int right) {
	if (dp[cur][right] == -1) {
		ll curbs = 0;
		for (int v: adj[cur]) {
			if (p==v) continue;
			ll lamt = dos(cur, v, 0) + abs(arr[cur][right] - arr[v][0]);
			ll ramt = dos(cur, v, 1) + abs(arr[cur][right] - arr[v][1]);
			curbs += max(lamt, ramt);
		}
		dp[cur][right] = curbs;
	}return dp[cur][right];
}
void solve() {
	int n;
	cin>>n;
	adj.assign(n, vi());
	arr.assign(n, vll());
	dp.assign(n, vll(2, -1));
	REP(i, n) {
		ll u,v;
		cin>>u>>v;
		arr[i].push_back(u);
		arr[i].push_back(v);
	}
	REP(i, n-1){
		int u,v;
		cin>>u>>v;u--;v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cout<<max(dos(-1, 0, 0), dos(-1,0,1))<<"\n";
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