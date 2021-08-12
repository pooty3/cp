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

void DFS(vvi &adj, bool *arr, int i) {
	arr[i] = true;
	FOREACH(it, adj[i]) {
		if (!arr[*it]) {
			DFS(adj, arr, *it);
		}
	}
}

void solve() {
	int n,m,l;
	cin>>n>>m>>l;
	vvi adj(n, vi());
	bool varr[n];
	memset(varr, 0, sizeof(varr));
	REP(i, m) {
		int x,y;
		cin>>x>>y;
		x--;y--;
		adj[x].push_back(y);
	}
	REP(i, l) {
		int z;
		cin>>z;
		z--;
		DFS(adj, varr,z);
	}
	int tot=0;
	REP(i, n) {
		if (varr[i]) tot++;
	}
	cout<<tot<<"\n";

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