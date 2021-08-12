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

void solve() {
	int n,m;
	cin>>n>>m;
	vvi adj(n, vi());
	REP(i,m) {
		int u,v;
		cin>>u>>v;u--;v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vi dist(n, INF);
	queue<int> q;
	q.push(0);
	dist[0] =0;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		FOREACH(it, adj[v]) {
			if (dist[*it]==INF) {
				dist[*it] = dist[v] +1;
				q.push(*it);
			}
		}
	}
	bool pos = true;
	REP(i, n) {
		if (dist[i]==INF) {
			pos = false;
			break;
		}
	}
	if (!pos) {
		cout<<"NO\n";
	} else {
		vi arr;
		REP(i, n) {
			if (dist[i]%2==0) {
				arr.push_back(i+1);
			}
		}
		cout<<"YES\n";
		cout<<arr.size()<<"\n";
		REP(i, arr.size()) {
			cout<<arr[i]<<" ";
		}
		cout<<"\n";

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