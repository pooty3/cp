#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define SORT(arr) sort(arr.begin(), arr.end())
#define LSOne(S) ((S)&-(S))
#define M_PI 3.1415926535897932384
#define INF 1e9
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
	int n;
	cin>>n;
	vi arr(n*n);
	REP(i, n*n) {
		cin>>arr[i];
	}
	vector<vii> adj(n*n, vii());
	REP(i, n*n) {
		if (i/n != 0) {
			adj[i].push_back({i-n, arr[i-n]+1});
		}
		if (i%n != 0) {
			adj[i].push_back({i-1, arr[i-1] +1});
		}
		if (i/n != n-1) {
			adj[i].push_back({i+n, arr[i+n] +1});
		}
		if (i%n != n-1) {
			adj[i].push_back({i+1, arr[i+1] +1});
		}
	}
	vi dist(n*n, INF);
	set<ii> dij;
	dist[0] = 1;
	REP(i, n*n) {
		dij.insert({dist[i], i});
	}
	while (!dij.empty()) {
		auto [d, u] = *dij.begin();
		dij.erase(dij.begin());
		for (auto &[v,w]: adj[u]) {
			if (dist[v] > max(w, dist[u])) {
				dij.erase(dij.find({dist[v],v}));
				dist[v] = max(w, dist[u]);
				dij.insert({dist[v],v});
			}
		}
	}
	cout<<dist[n*n-1] -1;
}