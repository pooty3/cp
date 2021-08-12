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
int md = 998244353;
int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	vll pow2(400,1);
	REPL(i,1, 401) {
		pow2[i] = pow2[i-1]*2;
		pow2[i]%=md;
	}
	int n;
	cin>>n;
	bool adj[n][n];
	int m;cin>>m;
	memset(adj, 0, sizeof(adj));
	vll noOfedges((1<<n), 0);
	REP(i,m) {
		int u,v;cin>>u>>v;u--;v--;
		adj[u][v] = true;
		adj[v][u] = true;
		REP(z, 1<<n) {
			if (z&(1<<u)) {
				if (z&(1<<v)) {
					noOfedges[z]++;
				}
			}
		}
	}
	vll camt((1<<n), 0);
	REP(i, n) {
		camt[(1<<i)] = 1;
	}
	REPL(i,1, 1<<n) {
		int idx=-1;
		for (int z = n-1; z >=0 ;z--) {
			if (i &(1<<z)) {
				idx = z;break;
			}
		}
		if (i==(1<<idx)) continue;
		int no = 0;
		REP(z, idx) {
			if (i &(1<<z)) {
				if (adj[z][idx]) {
					no++;
				}
			}
		}
		camt[i] = camt[i-(1<<idx)] * ((pow2[no]-1 + md)%md);
		camt[i]%=md;
	}
	REPL(i,1, n) {
		ll tot = 0;
		REP(z, 1<<n) {
			if (z&(1<<i)) {
				if (z&1) {
					tot += (camt[z] * pow2[noOfedges[(1<<n)-1-z]])%md;
					tot %= md;
				}	
			}
		}cout<<tot<<"\n";

	}
}