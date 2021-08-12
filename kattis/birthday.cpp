#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define SORT(arr) sort(arr.begin(), arr.end())
#define LSOne(S) ((S)&-(S))
#define M_PI 3.1415926535897932384
#define INF 1e9
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

int v;

bool bridge(vvi &adj, vi &dfs_low, vi &dfs_num, vi& dfs_parent, int n) {
	dfs_num[n] = v;
	dfs_low[n] = v;
	v++;
	FOREACH(it, adj[n]) {
		if (dfs_num[*it]==-1) {
			dfs_parent[*it] = n;
			if (bridge(adj, dfs_low, dfs_num, dfs_parent, *it)) {
				return true;
			} 
			if (dfs_low[*it]>dfs_num[n]) {
				return true;
			}
			dfs_low[n] = min(dfs_low[n], dfs_low[*it]);
		} else {
			if (*it != dfs_parent[n]) {
				dfs_low[n] = min(dfs_low[n], dfs_num[*it]);
			}
		}
	}
	return false;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int p,c;
	while (true) {
		cin>>p>>c;
		if (p==0&&c==0) break;
		vi dfs_low(p, -1);
		vi dfs_num(p,-1);
		vi dfs_parent(p, -1);
		vvi adj(p, vi());
		REP(i, c) {
			int a,b;
			cin>>a>>b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		v=0;
		if (bridge(adj, dfs_low, dfs_num, dfs_parent, 0)){
			cout<<"Yes\n";
		} else {
			if (v!=p) {
				cout<<"Yes\n";
			} else {
				cout<<"No\n";
			}
		}
	}

}