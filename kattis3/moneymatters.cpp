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
	int n,m;
	cin>>n>>m;
	vi arr(n);
	REP(i, n) {
		cin>>arr[i];
	}
	vvi adj(n, vi());
	REP(i, m) {
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	bool vis[n];
	memset(vis, 0, sizeof(vis));
	REP(i, n) {
		if (vis[i]) continue;
		stack<int> s;
		vis[i] = true;
		vi carr = {i};
		s.push(i);
		while (!s.empty()) {
			int u = s.top();s.pop();
			for (auto v: adj[u]) {
				if (!vis[v]) {
					carr.push_back(v);
					s.push(v);
					vis[v] = 1;
				}
			} 
		}
		int amt =0;
		for (auto j: carr) {
			amt += arr[j];
		}
		if (amt !=0) {
			cout<<"IMPOSSIBLE\n"; return 0;
		}
	}cout<<"POSSIBLE\n";

}