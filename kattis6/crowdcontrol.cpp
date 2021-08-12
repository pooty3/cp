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
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	vector<vii> adj(n,vii());
	map<ii, int> mp;
	REP(i, m) {
		int u,v,c;
		cin>>u>>v>>c;
		mp[{u,v}] = i;
		mp[{v,u}] = i;
		adj[u].push_back({v,-c});
		adj[v].push_back({u,-c});
	}
	vi p(n,0);
	vi dist(n, 0);
	dist[0] = -INF;
	set<ii> pq;
	REP(i, n) {
		pq.insert({dist[i],i});
	}
	while (!pq.empty()) {
		auto [d,u] = *pq.begin(); pq.erase(pq.begin());
		for (auto &[v,c]: adj[u]) {
			if (dist[v] > max(d, c)) {
				pq.erase(pq.find({dist[v],v}));
				dist[v] = max(d,c);
				p[v] = u;
				pq.insert({dist[v],v});
			}
		}
	}
	set<int> toremove;
	REP(i, m) {
		toremove.insert(i);
	}
	int cur = n-1;
	while (cur!=0) {
		toremove.erase(mp[{cur, p[cur]}]);
		cur = p[cur];
	}
	for (auto i: toremove){
		cout<<i<<" ";
	}
}