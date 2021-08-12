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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n,m,k;
	cin>>n>>m>>k;
	vvll dp(n, vll(1<<k, 0));
	vvi adj(n, vi());
	vi col(n);
	REP(i, n) {
		dp[i][0] = 1;
		cin>>col[i];
		col[i]--;
		dp[i][1<<(col[i])]++;
	}
	REP(i, m) {
		int u,v;
		cin>>u>>v;u--;v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	REPL(i,2,6) {
		REP(j, n) {
			REP(z, 1<<k) {
				if (__builtin_popcount(z)==i&&(z&(1<<col[j]))) {
					FOREACH(it, adj[j]) {
						dp[j][z] += dp[*it][z-(1<<col[j])];
					}
				}
			}
		}
	}
	ll tot =0;
	REP(i, n) {
		REP(j, 1<<k) {
			if (__builtin_popcount(j)>1) {
				tot += dp[i][j];
			}
		}
	}
	cout<<tot;



}