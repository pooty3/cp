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
	int n,m;
	cin>>n>>m;
	vector<vii> adj(n, vii());
	vi dist(n, INF);
	REP(i, m) {
		int u,v,w;
		cin>>u>>v>>w;u--;v--;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	deque<int> q;
	dist[0] =0;
	q.push_front(0);
	while(!q.empty()) {
		int u= q.front();
		q.pop_front();
		for (auto &[v, w] : adj[u]) {
			if (dist[v]> dist[u] +w) {
				dist[v] = dist[u] +w;
				if (w==0) {
					q.push_front(v);
				} else {
					q.push_back(v);
				}
			}
		}
	}
	cout<<dist[n-1];

}