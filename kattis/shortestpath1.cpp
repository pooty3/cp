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
	while (true) {
		int n,m,q,s;
		cin>>n>>m>>q>>s;
		if (n==0) break;
		vector<vii> adj(n, vii());
		vi dist(n, INF);
		dist[s] =0;
		REP(i,m) {
			int u,v,w;
			cin>>u>>v>>w;
			adj[u].push_back({v,w});
		}
		set<ii> que;
		REP(i, n) {
			que.emplace(dist[i], i);
		}
		while (!que.empty()){
			auto [d, u] = *que.begin();
			que.erase(que.begin());
			for (auto &[v,w] : adj[u]) {
				if (dist[u] + w < dist[v]) {
					que.erase(que.find({dist[v], v}));
					dist[v] = dist[u] + w;
					que.emplace(dist[v], v);
				}
			}
		
		}
		REP(i, q) {
			int v;
			cin>>v;
			if (dist[v]==INF) {
				cout<<"Impossible"<<"\n";
			} else {
				cout<<dist[v]<<"\n";
			}
		}
		cout<<"\n";

	}	

}