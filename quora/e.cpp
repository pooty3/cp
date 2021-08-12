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
vector<vector<pair<int,ll>>> adj;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	vll marr(n);
	REP(i, n) {
		cin>>marr[i];
	}
	adj.assign(n, vector<pair<int,ll>>());
	REP(i, n-1) {
		int u,v;
		ll c;
		cin>>u>>v>>c;
		u--;v--;
		adj[u].push_back({v,c});
		adj[v].push_back({u,c});
	}
	bool vit[n];
	REP(i, m) {
		int u,v;
		cin>>u>>v;u--;v--;
		queue<tuple<int,ll,ll>> q;
		memset(vit, 0, sizeof(vit));
		vit[u] = true;
		q.push({u, 0, 0});
		while (true) {
			auto &[uu, amt, mamt] = q.front();
			q.pop();
			if (uu == v) {
				cout<<-mamt<<"\n";
				break;
			}
			ll curamt = amt + marr[uu];
			FOREACH(it, adj[uu]) {
				if (vit[it->first]) continue;
				vit[it->first]= true;
				ll namt = curamt- (it->second);
				q.push({it->first, namt, min(mamt, namt)});
			}

		}
	}
}