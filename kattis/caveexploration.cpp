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

int counter;
vvi adj;
vi dfs_low;
vi dfs_num;
vi p;
set<ii> b;
vi vist;
void bridge(int n) {
	dfs_low[n] = counter;
	dfs_num[n] = counter;
	counter++;
	FOREACH(it, adj[n]) {
		if (dfs_num[*it]==-1) {
			p[*it] = n;
			bridge(*it);
			if (dfs_low[*it]>dfs_num[n]) {
				b.insert({*it, n});
				b.insert({n, *it});
			}
			dfs_low[n] = min(dfs_low[*it], dfs_low[n]);
		} else {
			if (p[n]!=*it) {
				dfs_low[n] = min(dfs_num[*it], dfs_low[n]); 
			}
		}
	}
}

void DFS(int n) {
	vist[n] =1;
	FOREACH(it, adj[n]) {
		if (vist[*it]==-1 && b.find({*it, n})==b.end()) {
			DFS(*it);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	adj.assign(n, vi());
	dfs_low.assign(n, -1);
	dfs_num.assign(n, -1);
	p.assign(n, -1);
	REP(i,m) {
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	counter=0;
	bridge(0);
	vist.assign(n, -1);
	DFS(0);
	int tot=0;
	REP(i,n) {
		if (vist[i]==1) {
			tot++;
		}
	}
	cout<<tot;


}