#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define SORT(arr) sort(arr.begin(), arr.end())
#define LSOne(S) ((S)&-(S))
#define M_PI 3.1415926535897932384
#define INF 1999999999
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
	vector<vector<pair<int, ll>>> adj(4*n, vector<pair<int, ll>>());
	REP(i, m) {
		int u,v;
		ll w;
		cin>>u>>v>>w;
		u--;v--;
		REP(j, 4) {
			adj[u+n*j].push_back({v+n*j, w});
			adj[v+n*j].push_back({u+n*j, w});
		} 
		adj[u].push_back({v+n, 0});
		adj[v].push_back({u+n, 0});
		adj[u+2*n].push_back({v+3*n, 0});
		adj[v+2*n].push_back({u+3*n, 0});
		adj[u+n].push_back({v+3*n, 2*w});
		adj[v+n].push_back({u+3*n, 2*w});
		adj[u].push_back({v+2*n, 2*w});
		adj[v].push_back({u+2*n, 2*w});

	}
	vll dist(4*n, INF*(ll)INF);
	dist[0] = 0;
	dist[3*n] = 0;
	set<pair<ll, int>> mp;
	REP(i, 4*n) {
		mp.emplace(dist[i], i);
	}
	while (!mp.empty()) {
		auto [d, u] = *mp.begin();
		mp.erase(mp.begin());
		for (auto &[v, we] : adj[u]) {
			ll nmin = d + we;
			if (nmin < dist[v]) {
				mp.erase(mp.find({dist[v], v}));
				dist[v] = nmin;
				mp.emplace(dist[v], v);
			}
		}
	}
	REPL(i, 1, n) {
		cout<<dist[i+3*n]<<" ";
	}




}