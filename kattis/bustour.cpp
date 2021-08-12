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
int getmask(vi &arr) {
	int tot =0;
	REP(i, arr.size()) {
		tot+=arr[i];
		tot*=2;
	}
	return tot/2;
}

int mindis(vvi &dp, vvi &dist, int mask, int end, bool attr) {
	if (mask==0) {
		if (attr) {
			return dist[dist.size()-1][end];
		} else {
			return dist[0][end];
		}
	} 
	if (dp[mask][end]==-1) {
		int mn = INF;
		int m = mask;
		while (m) {
			int l = LSOne(m);
			int ind = __builtin_ctz(l) +1;
			mn = min(mn, mindis(dp, dist, mask^l, ind , attr) + dist[ind][end]);
			m -= l;
		}
		dp[mask][end] = mn;
	}
	return dp[mask][end];
}

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	int tc=0;
	int n,m;
	while(cin>>n>>m) {
		tc++;
		vvi adj(n, vi(n, INF));
		REP(i, n) {
			adj[i][i] =0;
		}
		REP(i, m) {
			int u,v,d;
			cin>>u>>v>>d;
			adj[u][v] = d;
			adj[v][u] = d;
		}
		vvi dist = adj;
		REP(i, n) {
			REP(j, n) {
				REP(k, n) {
					dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
				}
			}
		}
		int ho = n/2 -1;
		vvi dpS(1<<(n-2), vi(n-1,-1));
		vvi dpA(1<<(n-2), vi(n-1,-1));
		vi perm(n-2,0);
		REP(i, ho) {
			if (i < ho) {
				perm[i] = 1;
			} 
		}
		SORT(perm);
		int mn = INF;
		do {
			int mask1= getmask(perm);
			int mask2 = (1<<(n-2)) - mask1-1;
			REPL(i, 1, n-1) {
				REPL(j, 1, n-1) {
					mn = min(mn, mindis(dpS, dist, mask1, i, false)
						+ mindis(dpA, dist, mask2, i, true) +
						mindis(dpA, dist, mask1, j, true) +
						mindis(dpS, dist, mask2, j, false));
				}
			}
		} while (next_permutation(perm.begin(), perm.end()));
		printf("Case %d: %d\n", tc,mn);
	}

}