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

struct edge{
	int v,t0, p, d;
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true) {
		int n,m,q,s;
		cin>>n>>m>>q>>s;
		if (n==0)break;
		vector<vector<edge>> adj(n, vector<edge>());
		REP(i, m) {
			int u,v,t0,p,d;
			cin>>u>>v>>t0>>p>>d;
			adj[u].push_back({v,t0,p,d});
		}
		vi dist(n, INF);
		dist[s] = 0;
		set<ii> mp;
		REP(i,n) {
			mp.emplace(dist[i],i);
		}
		while (!mp.empty()) {
			int u = mp.begin()->second;
			mp.erase(mp.begin());
			for (auto &[v,t0,p,d] : adj[u]) {
				int dst;
				if (p==0&& t0<dist[u]) {
					continue;
				} else {
					if (t0>= dist[u]) {
						dst = t0 + d;
					} else {
						dst = ((int)ceil(((double)(dist[u]-t0))/p))* p + t0 + d;
					}
					if (dst<dist[v]) {
						mp.erase(mp.find({dist[v],v}));
						dist[v] = dst;
						mp.insert({dist[v],v});
					}
				}
			}
		}
		REP(i, q) {
			int v;
			cin>>v;
			if (dist[v]==INF){cout<<"Impossible\n";}
			else {
				cout<<dist[v]<<"\n";
			}

		}
		cout<<"\n";
	}


}