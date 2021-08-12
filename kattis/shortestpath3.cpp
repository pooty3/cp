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
		REP(i, m) {
			int u,v,w;
			cin>>u>>v>>w;
			adj[u].push_back({v, w});
		}
		vi dist(n, INF);
		dist[s] = 0; 
		REP(i, n-1) {
			REP(u, n) {
				if (dist[u]!=INF) {
		 			for (auto &[v, w] : adj[u]) {
		 				dist[v] = min(dist[v], dist[u] +w);
					}
				}
			}
		}
		vi dist2 = dist;
		REP(u, n) {
			if (dist2[u]!=INF) {
		 			for (auto &[v, w] : adj[u]) {
		 				dist2[v] = min(dist2[v], dist2[u] +w);
					}
				}
		}
		set<int> inf;
		REP(i, n) {
			if (dist2[i] < dist[i]) {
				inf.insert(i);
			}
		}
		stack<int> st;
		FOREACH(it, inf) {
			st.push(*it);
		}
		bool varr[n];
		memset(varr, 0 , sizeof(varr));
		while (!st.empty()) {
			int v = st.top();
			st.pop();
			if (!varr[v]) {
				dist[v] = -INF;
				varr[v] = true;
				FOREACH(it, adj[v]) {
					st.push(it->first);
				}
			}
		}
		REP(i, q) {
			int x;
			cin>>x;
			if (dist[x]==INF) {
				cout<<"Impossible";
			} else if (dist[x] == -INF) {
				cout<<"-Infinity";
			} else {
				cout<<dist[x];
			}cout<<"\n";
		}
		cout<<"\n";
	}

}