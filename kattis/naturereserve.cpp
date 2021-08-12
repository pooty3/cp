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
	int n, m, l, s;
	cin>>n>>m>>l>>s;
	vector<vii> adj(n+1, vii());
	bool vist[n+1];
	memset(vist, 0 , sizeof(vist));
	REP(i, s) {
		int x;
		cin>>x;
		adj[0].push_back({x,0});
	}
	REP(i, m) {
		int x,y,w;
		cin>>x>>y>>w;
		adj[x].push_back({y,w});
		adj[y].push_back({x,w});
	}
	priority_queue<ii> pq;
	ll tot = ((long)l)*(n-s);
	pq.push({0,0});
	while (!pq.empty()) {
		auto [w,i] = pq.top();
		pq.pop();
		if (!vist[i]) {
			vist[i] = true;
			tot += -w;
			for (auto [j,w1]: adj[i]) {
				if (!vist[j]) {
					pq.push({-w1, j});
				}
			}
		}
	}
	cout<<tot<<"\n";

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