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
bool v[1000000];
stack<int> s;
string str = "";
vii dep;
void toposort(int id) {
	if (!v[id]) {
		v[id]= true;
		FOREACH(it, adj[id]) {
			toposort(*it);
		}
		s.push(id);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	adj.assign(n, vi());
	REP(i, m) {
		int u, v;
		cin>>u>>v;
		u--;v--;
		adj[u].push_back(v);
		dep.push_back({u,v});
	}
	memset(v, 0, sizeof(v));
	REP(i, n) {
		toposort(i);
	}
	vi ord(n);
	REP(i, n) {

		ord[s.top()] = i;
		str+= to_string(s.top()+1) + "\n";
		s.pop();
	}
	for (auto &[u,v] : dep) {
		if (ord[u] > ord[v]) {
			str = "IMPOSSIBLE";
		}
	}
	cout<<str;


}