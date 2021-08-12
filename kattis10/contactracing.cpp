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
	int n,d;
	cin>>n>>d;
	vi inf;
	map<ii, bool> sarr;
	int c;
	cin>>c;
	bool vis[n];
	memset(vis, 0, sizeof(vis));
	REP(i, c) {
		int x;cin>>x;
		x--;
		inf.push_back(x);
		vis[x] = true;
	}
	REP(i, n) {
		int s,e;
		cin>>s>>e;
		sarr.insert({{s,i}, true});
		sarr.insert({{e+1,i-n}, false});
	}
	vvi adj(n, vi());
	set<int> curpeople;
	for (auto [p, t]: sarr) {
		int u = p.second;
		if (t) {
			for (auto v: curpeople) {
				adj[u].push_back(v);
				adj[v].push_back(u);
			}
			curpeople.insert(u);
		} else {
			curpeople.erase(u+n);
		}
	}
	REP(i, d) {
		vi narr;
		for (auto u: inf) {
			for (auto v: adj[u]) {
				if (!vis[v]) {
					narr.push_back(v);
					vis[v] = true;
				}
			}
		}
		inf = narr;
	}
	REP(i, n) {
		if (vis[i]) {
			cout<<(i+1)<<" ";
		}
	}

}