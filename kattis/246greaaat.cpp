#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define SORT(arr) sort(arr.begin(), arr.end())
#define LSOne(S) ((S)&-(S))
#define M_PI 3.1415926535897932384
#define INF 1e18
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

//tle?
bool vist[500000];
void topsort(stack<int> &ord, vector<vii> &adj, int cur, int tar) {
	vist[cur] = true;
	if (cur != tar ) {
		for (auto &[v, w] : adj[cur]) {
		if (!vist[v]) {
			topsort(ord, adj, v,tar);
		}
	}
	}
	ord.push(cur);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n,t;
	cin>>n>>t;
	vector<ii> carr;
	carr.push_back({1,1});
	REP(i, n) {
		int s, d;
		cin>>s>>d;
		carr.push_back({s,d});
	}
	vector<vii> adj (2*t+1, vii());
	REP(i, 2*t+1) {
		REP(j, carr.size()) {
			int v = i + carr[j].first;
			if (v>=0&&v<=2*t) {
				adj[i].push_back({v, j});
			}
		}
	}
	stack<int> ord;
	memset(vist, 0, sizeof(vist));
	topsort(ord, adj, t, 2*t);
	vll dist(2*t+1, INF);
	dist[t] =0;
	vi mp(2*t+1, -1);
	dist[0] =0;
	while (true) {
		int u = ord.top();
		ord.pop();
		if (u == 2*t) break;
		for (auto &[v, j] : adj[u]) {
			int ne = dist[u]+carr[j].second;
			if (dist[v] > ne) {
				dist[v] = ne;
				mp[v] = j;
			}
		}
	}
	int cur = 2*t;
	vi cheers;
	while (cur != t) {
		int ind = mp[cur];
		cheers.push_back(ind+1);
		cur -= carr[ind].first;
	}
	cout<<cheers.size()<<"\n";
	FOREACH(it, cheers) {
		cout<<(*it)<<" ";
	}


}