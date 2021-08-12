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

void solve() {
	int n;cin>>n;
	set<ii> edges;
	vvi adj(n, vi());
	REP(i, n-1) {
		int u,v;
		cin>>u>>v;
		u--;v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
		edges.insert({u,v});
		edges.insert({v,u});
	}
	vi dist(n,-1);
	queue<int> q;
	dist[0] =0;
	q.push(0);
	while (!q.empty()) {
		auto u = q.front(); q.pop();
		for (auto v:adj[u]) {
			if (dist[v]==-1){
				dist[v]= dist[u] +1;
				q.push(v);
			}
 		}
	}
	int curb =0;
	REP(i,n) {
		if (dist[i]>dist[curb]) {
			curb = i;
		}
	}
	dist.assign(n, -1);
	vi parr(n,-1);
	dist[curb] = 0;
	q.push(curb);
	while (!q.empty()) {
		auto u = q.front(); q.pop();
		for (auto v:adj[u]) {
			if (dist[v]==-1){
				parr[v] = u;
				dist[v]= dist[u] +1;
				q.push(v);
			}
 		}
	}
	REP(i,n) {
		if (dist[i]>dist[curb]) {
			curb = i;
		}
	}
	int curend = curb;
	set<int> curv;
	REP(i, n) {
		curv.insert(i);
	}
	while (curb != -1) {
		curv.erase(curb);
		if (parr[curb] != -1) {
			edges.erase({curb, parr[curb]});
			edges.erase({parr[curb], curb});
		}
		curb = parr[curb];
	}
	vector<tuple<int,int,int,int>> tarr;
	int count = 0;
	while (!edges.empty()) {
		count++;
		auto [u,v] = *edges.begin();
		edges.erase({u,v});
		edges.erase({v,u});
		tarr.push_back({u,v, *curv.begin(), curend});
		curend = *curv.begin();
		curv.erase(curv.begin());
	}
	cout<<count<<"\n";
	for (auto [i,j,x,y]: tarr) {
		cout<<i+1<<" "<<j+1<<" "<<x+1<<" "<<y+1<<"\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int tc;
	cin>>tc;
	REP(i, tc) {
		solve();
	}

}