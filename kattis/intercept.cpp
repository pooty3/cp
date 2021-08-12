#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define SORT(arr) sort(arr.begin(), arr.end())
#define LSOne(S) ((S)&-(S))
#define M_PI 3.1415926535897932384
#define INF 999999999999999
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

vi arti, dfslow, dfsnum, dfsp;
int co;
void findart(vvi &adj, int n) {
	dfslow[n] = co;
	dfsnum[n] = co;
	co++;
	FOREACH(it, adj[n]) {
		if (dfsnum[*it]==-1) {
			dfsp[*it] = n;
			findart(adj, *it);
			if (dfslow[*it]>=dfsnum[n]) {
				arti[n] = 1;
			}
			dfslow[n] =  min(dfslow[n], dfslow[*it]);
		} else {
			if (dfsp[n] != *it) {
				dfslow[n] = min(dfslow[n], dfsnum[*it]); 
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	vector<vector<pair<int,ll>>> adj(n, vector<pair<int,ll>>());
	REP(i, m) {
		int u,v;
		ll w;
		cin>>u>>v>>w;
		adj[u].push_back({v, w});
	}
	int s,t;
	cin>>s>>t;
	map<pair<ll, int>, vi> pq;
	vvi badj2(n, vi());
	vll dist(n, INF);
	dist[s] =0;
	for (auto &[v, w] : adj[s]) {
		pq.insert({{w,v}, {s}});
		dist[v] = w;
	}
	while (!pq.empty()) {
		auto [p, ve] = *pq.begin();
		pq.erase(pq.begin());
		badj2[p.second] = ve;
		for (auto &[v, w] : adj[p.second]) {
			if (dist[p.second] + w < dist[v]) {
				pq.erase({dist[v], v});
				dist[v] = dist[p.second] + w;
				pq.insert({{dist[v], v}, {p.second}});
			} else if (dist[p.second]+w==dist[v]) {
				pq[{dist[v], v}].push_back(p.second);
			} else {}
		}
	}
	vi added(n, -1);
	vvi adj3(n, vi()); 
	queue<int> q;
	q.push(t);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		if (added[u]==-1) {
			added[u] = 1;
			FOREACH(it, badj2[u]) {
				adj3[*it].push_back(u);
				adj3[u].push_back(*it);
				q.push(*it);
			}
		}
	}
	arti.assign(n, -1);
	dfslow.assign(n, -1);
	dfsnum.assign(n, -1);
	dfsp.assign(n, -1);
	co=0;
	findart(adj3, s);
	REP(i, n) {
		if (arti[i]==1 ||i == s||i ==t) {
			cout<<i<<" ";
		}
	}





}