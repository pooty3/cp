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

int idx;
vi slab;
vi elab;
set<ii> curv;
void kdfs(int cur, vvi &adj) {
	slab[cur]=idx;
	idx++;
	for (auto v: adj[cur]){
		kdfs(v, adj);
	}
	elab[cur]=idx;
	idx++;
}
int curmx=0;
void tryadd(int cur, set<ii> &del) {
	if (curv.size()==0) {
		curv.insert({slab[cur], cur});
		return;
	}
	auto it = curv.upper_bound({slab[cur], 0});
	if (it != curv.end()) {
		if (elab[it->second] < elab[cur]) {
			return;
		}
	}
	if (it != curv.begin()) {
		it = prev(it);
		if (elab[it->second] > elab[cur]) {
			del.insert({it->first, it->second});
			curv.erase(it);
		}
	}
	curv.insert({slab[cur], cur});

}
void sdfs(int cur, vvi &adj) {
	set<ii> del;
	tryadd(cur, del);
	for (auto v: adj[cur]) {
		sdfs(v, adj);
	}
	curmx = max(curmx, (int)curv.size());
	auto it =curv.find({slab[cur], cur});
	if (it != curv.end()) {
		curv.erase(it);
	}
	for (auto [i,j]: del) {
		curv.insert({i,j});
	}
}
void solve() {
	int n;
	cin>>n;
	idx=0;
	curv.clear();
	vvi sadj(n, vi());
	vvi kadj(n, vi());
	REPL(i,1, n) {
		int u;cin>>u;u--;
		sadj[u].push_back(i);
	}
	REPL(i,1, n) {
		int u;cin>>u;u--;
		kadj[u].push_back(i);
	}
	slab.assign(n,-1);
	elab.assign(n,-1);
	curmx =0;
	kdfs(0, kadj);
	sdfs(0, sadj);
	cout<<curmx<<"\n";
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