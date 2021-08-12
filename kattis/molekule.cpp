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
	int n;
	cin>>n;
	vi col(n,-1);
	vvi adj(n, vi());
	vii parr;
	REP(i, n-1) {
		int u,v;
		cin>>u>>v;u--;v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
		parr.push_back({u,v});
	} 
	col[0] = 0;
	queue<int>q;
	q.push(0);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		FOREACH(it, adj[u]) {
			if (col[*it]==-1) {
				col[*it] = 1 - col[u];
				q.push(*it);
			}
		}
	}
	for (auto &[u,v]: parr) {
		if (col[u]==0) {
			cout<<0;
		} else {
			cout<<1;
		}
		cout<<"\n";
	}



}