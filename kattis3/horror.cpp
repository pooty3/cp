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
	int n,h,l;cin>>n>>h>>l;
	vi dist(n, INF);
	queue<int> q;
	REP(i, h) {
		int j;cin>>j;
		dist[j] =0;
		q.push(j);
	}
	vvi adj(n, vi());
	REP(i, l) {
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	while (!q.empty()) {
		int u= q.front();q.pop();
		for (auto v: adj[u]) {
			if (dist[v] == INF) {
				dist[v] = dist[u] +1;
				q.push(v);
			}
		}
	}
	ii mn = {0, -n};
	REP(i, n) {
		mn = max(mn, {dist[i], -i});
	}
	cout<<-mn.second;


}