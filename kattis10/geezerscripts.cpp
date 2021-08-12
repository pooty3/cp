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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	ll a,h;cin>>a>>h;
	int n,m;
	cin>>n>>m;
	vector<vector<pair<int, ll>>> adj(n, vector<pair<int,ll>>());
	REP(i, m) {
		int u,v;
		ll aa,hh;
		cin>>u>>v>>aa>>hh;u--;v--;
		ll hits = hh/a;
		if (hh%a == 0) {
			hits--;
		}
		adj[u].push_back({v, hits*aa});
	}
	vll dist(n, 1e18);
	dist[0] = 0;
	set<pair<ll, int>> pq;
	REP(i, n) {
		pq.insert({dist[i], i});
	}
	while (!pq.empty()) {
		auto [curd, u] = *pq.begin();
		pq.erase(pq.begin());
		if (curd >= h) {
			cout<<"Oh no"; return 0;
		} 
		if (u == n-1) break;
		for (auto [v, dd]: adj[u]) {
			if (dd+dist[u] < dist[v]) {
				pq.erase(pq.find({dist[v], v}));
				dist[v] = dist[u] + dd;
				pq.insert({dist[v], v});
			}
		}
	}	cout<<h-dist[n-1]<<"\n";
}