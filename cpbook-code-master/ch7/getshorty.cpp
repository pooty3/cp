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
	while (true) {
		int n,m;
		cin>>n>>m;
		if (n==0) break;
		vector<vector<pair<int, ld>>> adj(n, vector<pair<int, ld>>());
		vector<ld> dist(n, 0.0);
		dist[0] = 1;
		REP(i, m) {
			int u,v;
			ld x;
			cin>>u>>v>>x;
			adj[u].push_back({v,x});
			adj[v].push_back({u,x});
		}
		set<pair<ld, int>> s;
		REP(i, n) {
			s.insert({dist[i], i});
		}
		while (!s.empty()) {
			auto [d, u] = *prev(s.end());
			s.erase(prev(s.end()));
			for (auto [v,w]: adj[u]) {
				if (dist[v] < dist[u] * w) {
					s.erase(s.find({dist[v], v}));
					dist[v] = dist[u] * w;
					s.insert({dist[v], v});
				}
			}
		}printf("%.4f\n", dist[n-1]);
	}
}