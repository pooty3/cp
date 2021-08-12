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
bool vist[300005];
vector<set<int>> adj;
vi vistarr;
void dodfs(int cur) {
	vistarr.push_back(cur);
	vist[cur] = true;
	for (auto v: adj[cur]) {
		if (!vist[v]) {
			dodfs(v);
			vistarr.push_back(cur);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;cin>>n;
	adj.assign(n, set<int>());
	REP(i, n-1) {
		int u,v;cin>>u>>v;
		u--;v--;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	memset(vist, 0, sizeof(vist));
	dodfs(0);
	for (auto j: vistarr) {
		cout<<(j+1)<<" ";
	}
}