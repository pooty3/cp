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

bool vist[100000];
vi cmp;
void DFS1(int u, stack<int> &s, vvi &adj) {
	vist[u] = true;
	FOREACH(it, adj[u]) {
		if (!vist[*it]) {
			DFS1(*it, s, adj);
		}

	}
	s.push(u);
}
void DFS2(int u, vvi &adj, int c) {
	vist[u] =true;
	cmp[u] =c;
	FOREACH(it, adj[u]) {
		if (!vist[*it]) {
			DFS2(*it, adj, c);
		}

	}
}

void solve() {
	int n,m;
	cin>>n>>m;
	vvi adj(n, vi());
	vvi tadj(n, vi());
	REP(i, m) {
		int u,v;
		cin>>u>>v;u--;v--;
		adj[u].push_back(v);
		tadj[v].push_back(u);
	}
	stack<int> s;
	memset(vist, 0 ,sizeof(vist) );
	REP(i, n) {
		if (!vist[i]) {
			DFS1(i, s,adj);
		}
	}
	memset(vist, 0, sizeof(vist));
	int counter2=0;
	cmp.assign(n, -1);
	while (!s.empty()) {
		int v = s.top();s.pop();
		if (!vist[v]) {
			DFS2(v, tadj, counter2);
			counter2++;
		}
	}
	vi out(counter2, 0);
	vi in(counter2, 0);
	if (counter2==1) {
		cout<<0<<"\n";
	} else {
		vi out(counter2, 0);
		vi in(counter2, 0);
		REP(i, n) {
			FOREACH(it, adj[i]) {
				if (cmp[*it]!=cmp[i]) {
					out[cmp[i]]++;
					in[cmp[*it]]++;
				}
			}
		}
		int sink=0, source =0;
		REP(i, counter2) {
			if (out[i]==0) {
				sink++;
			} 
			if (in[i]==0) {
				source++;
			}
		}
		cout<<max(sink, source)<<"\n";
	}
	

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