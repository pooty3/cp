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

void solve() {
	int n,m;
	cin>>n>>m;
	vvi adj(n, vi());
	REP(i, m) {
		int u,v;
		cin>>u>>v;
		u--;v--;
		adj[u].push_back(v);
	}
	vi dist(n, INF);
	queue<int> q;
	dist[0] =0;
	q.push(0);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		FOREACH(it, adj[v]) {
			if (dist[*it]>dist[v] +1) {
				dist[*it] = dist[v] +1;
				q.push(*it);
			}
		}
	}
	vvi mp(n, vi());
	REP(i, n) {
		mp[dist[i]].push_back(i);
	}
	vi mind(n, INF);
	for (int i = n-1; i >=0; i--) {
		FOREACH(it, mp[i]) {
			mind[*it] = dist[*it];
			FOREACH(it2, adj[*it]) {
				if (dist[*it2]<= dist[*it]) {
					mind[*it] = min(dist[*it2], mind[*it]);
				} else {
					mind[*it] = min(mind[*it2], mind[*it]);
				}
			}
		}
	}
	REP(i, n) {
		cout<<mind[i]<<" ";
	}
	cout<<"\n";
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