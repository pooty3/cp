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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	vvi adj(2*n,vi());
	REP(i, n) {
		adj[i].push_back(n+i);
	}
	REP(i, m) {
		int u,v;
		cin>>u>>v;
		if (u<0) {
			adj[-u-1].push_back(v-1);
			adj[-u-1+n].push_back(v-1+n);
		} else {
			adj[u-1].push_back(v-1+n);
		}
	}
	bool vist[2*n];
	memset(vist, 0, sizeof(vist));
	stack<int> s;
	s.push(0);
	int tot=0;
	while (!s.empty()) {
		int v= s.top();
		s.pop();
		if (vist[v]) {
			continue;
		}
		vist[v] = true;
		if (adj[v].size()==0) {
			tot++;
		} else {
			FOREACH(it, adj[v]) {
				if (!vist[*it]) {
					s.push(*it);
				} 
			}
		}
	}
	cout<<tot;
}