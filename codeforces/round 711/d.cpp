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
	vi dys(m+1,-1);
	dys[0] = 0;
	REP(dd, n) {
		int t;
		ll x,y;
		cin>>t>>x>>y;
		vvi adj(m+2, vi());
		REP(i,m+1) {
			if (dys[i]==-1) continue;
			adj[m+1].push_back(i);
		}
		REP(i, m+1) {
			if (t == 1) {
				int v = (x-1)/100000 + 1;
				if (i+v<=m) {
					adj[i].push_back(i+v);
				}
			}
			if (t ==2) {
				if (i==0) continue;
				ll cur = i;
				cur *= x;
				cur = (cur-1)/100000+1;
				if (cur <= m) {
					adj[i].push_back((int)cur);
				}
			}
		}
		vi dist(m+2, INF);
		dist[m+1] = 0;
		queue<int> q; q.push(m+1);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (auto &v: adj[u]) {
				if (dist[v]!=INF) continue;
				dist[v] = dist[u]+1;
				q.push(v);
			}
		}
		REP(z, m+1) {
			if (dys[z] != -1) continue;
			if (dist[z]<= y+1) {
				dys[z] = dd+1;
			}
		}
	}
	REPL(i, 1,m+1) {
		cout<<dys[i]<<" ";
	}
}