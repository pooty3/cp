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
	int p,t;
	cin>>p>>t;
	vector<vii> adj(p, vii());
	REP(i, t) {
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	vi dist(p, INF);
	dist[0] =0;

	vi bw(p, 0);
	vvi barr(p, vi());
	set<ii> pq;
	REP(i, p) {
		pq.emplace(dist[i], i);
	}

	while (!pq.empty()) {
		int u = pq.begin()->second;
		pq.erase(pq.begin());
		for (auto &[v, w]: adj[u]) {
			if (dist[v]== dist[u] + w) {
				bw[v] += w;
				barr[v].push_back(u);
			} else if (dist[v]> dist[u] + w) {
				pq.erase(pq.find({dist[v], v}));
				dist[v] = dist[u] + w;
				bw[v]= w;
				barr[v] = {u};
				pq.insert({dist[v], v});
			} else {

			}
		}
	}
	int tot =0;
	queue<int> q;
	bool vist[p];
	memset(vist, false , sizeof(vist));

	q.push(p-1);
	vist[p-1] = true;
	while (!q.empty()) {
		int v= q.front();
		tot += bw[v];
		q.pop();
		FOREACH(it, barr[v]) {
			if (!vist[*it]) {
				vist[*it] = true;
				q.push(*it);
			}
		} 
	}
	cout<<tot*2;


}

