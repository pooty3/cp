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
	int c,p,x,l;
	cin>>c>>p>>x>>l;
	bool iarr[c];
	memset(iarr, 0, sizeof(iarr));
	vi sarr(c,0);
	vector<unordered_set<int>> adj(c, unordered_set<int>());
	REP(i, p) {
		int u,v;
		cin>>u>>v;u--;v--;
		adj[u].insert(v);
		adj[v].insert(u);
		sarr[u]++;
		sarr[v]++;
	}
	queue<int> q;
	q.push(l-1);
	iarr[l-1] = true; 
	while (!q.empty()) {
		int id = q.front();
		if (id==x-1) break;
		q.pop();
		FOREACH(it, adj[id]) {
			if (!iarr[*it]) {
				adj[*it].erase(id);
				if (adj[*it].size()*2 <= sarr[*it]) {
					iarr[*it] = true;
					q.push(*it);
				}
			}
		}
	}
	cout<<(iarr[x-1]?"leave":"stay");

}