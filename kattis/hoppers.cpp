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

vvi adj;
vi col;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	adj.assign(n, vi());
	REP(i, m) {
		int u,v;
		cin>>u>>v;
		u--;v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	col.assign(n, -1);
	queue<int> q;
	int tot =0;
	bool odd =false;
	REP(i, n) {
		if (col[i]==-1) {
			tot++;
			q.push(i);
			col[i] =0;
			while (!q.empty()) {
				int u = q.front(); q.pop();
				FOREACH(it, adj[u]) {
					if (col[*it]==-1) {
						col[*it] = 1-col[u];
						q.push(*it);
					} else if (col[*it]==col[u]){
						odd = true;
					} else {}
				}
			}
		}
	}
	if (odd) {
		tot--;
	}
	cout<<tot;



}