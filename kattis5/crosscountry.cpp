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
	int n,s,t;cin>>n>>s>>t;
	vvi arr(n, vi(n));
	REP(i, n) {
		REP(j ,n) {
			cin>>arr[i][j];
		}
	}
	vi dist(n, INF);
	dist[s] = 0;
	set<ii>pq;
	REP(i, n) {
		pq.insert({dist[i], i});
	}
	while (!pq.empty()) {
		auto [d, u] = *pq.begin(); pq.erase(pq.begin());
		REP(i, n) {
			if (dist[i]>dist[u]+arr[u][i]) {
				pq.erase({dist[i], i});
				dist[i] = dist[u] + arr[u][i];
				pq.insert({dist[i], i});
			}
		}
	}
	cout<<dist[t];

}