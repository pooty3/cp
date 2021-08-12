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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n,k;
	cin>>n>>k;
	vvi arr(n, vi(n));
	REP(i, n) {
		REP(j, n) {
			cin>>arr[i][j];
		}
	}
	vector<vii> adj(n*n+1, vii());
	REP(i, n) {
		REP(j, n) {
			int v = arr[i][j];
			if (v == 1) {
				adj[n*n].push_back({i*n+j, 0});
			}
			REP(k, n) {
				REP(g, n) {
					if(v == arr[k][g]-1) {
						adj[i*n+j].push_back({k*n+g, abs(k-i)+abs(g-j)});
					}
				}
			}
		}
	}
	vi dist(n*n+1, INF);
	dist[n*n]=0;
	set<ii> pq;
	pq.insert({0, n*n});
	int ans =-1;
	while (!pq.empty()) {
		auto [d,u] = *pq.begin(); pq.erase(pq.begin());
		if (u != n*n && arr[u/n][u%n] == k) {
			ans = d;
			break;
		}
		for (auto [v,w]: adj[u]) {
			if (dist[v]> dist[u]+w ) {
				auto it = pq.find({dist[v], v});
				if (it!=pq.end()) {
					pq.erase(it);
				}
				dist[v] = dist[u] + w;
				pq.emplace(dist[v],v);
			}
		}
	}
	cout<<ans;
}