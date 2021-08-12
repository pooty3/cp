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
	int n,t;
	cin>>n>>t;
	vi arr(n);
	vector<set<int>> adj(3601,set<int>());
	REP(i, n) {
		cin>>arr[i];
	}
	REP(i, 3601) {
		REP(j, n) {
			adj[i].insert(min(3600,max(0, i+arr[j])));
		}
	}
	vi dist(3601, INF);
	dist[0] =0;
	bool vist[3601];
	memset(vist, 0, sizeof(vist));
	queue<int> q;
	q.push(0);
	vist[0] = true;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		FOREACH(it, adj[v]) {
			if (!vist[*it]) {
				dist[*it] = 1+ dist[v];
				q.push(*it);
				vist[*it] = true;
			}
		}
	}
	int cur=t;
	while (true) {
		if (dist[cur]!=INF) {
			cout<<dist[cur]<<" "<<(cur-t)<<"\n";
			break;
		} else {
			cur++;
		}
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