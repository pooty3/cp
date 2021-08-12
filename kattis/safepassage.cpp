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
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	int n;
	cin>>n;
	vi arr(n);
	vi dist(1<<(n+1), INF);
	dist[0] = 0;
	REP(i, n) {
		cin>>arr[i];
	}
	set<ii> s;
	REP(i, dist.size()) {
		s.emplace(dist[i], i);
	}
	while (true) {
		auto [t, u] = *s.begin();
		if (u==((1<<(n+1))-1)) {break;}
		s.erase(s.begin());
		vii narr;
		if ((1<<n)&u) {
			REP(i, n) {
				if ((1<<i)&u) {
					narr.push_back({u - (1<<n) - (1<<i), arr[i]});
				}
			}
		} else {
			vi garr;
			REP(i, n) {
				if (((1<<i)&u) == 0) {
					garr.push_back(i);
				}
			}
			vi perm;
			REP(i, garr.size()-2) {
				perm.push_back(0);
			}
			perm.push_back(1);
			perm.push_back(1);
			do {
				int net = u + (1<<n);
				int mx = 0;
				REP(i, perm.size()) {
					if (perm[i]==1) {
						mx = max(mx, arr[garr[i]]);
						net += (1<<(garr[i]));
					}
				}
				narr.push_back({net, mx});
			} while (next_permutation(perm.begin(), perm.end()));
		}
		for (auto &[v, di] : narr) {
			if (dist[v] > dist[u] + di) {
				s.erase(s.find({dist[v], v}));
				dist[v]= dist[u] + di;
				s.emplace(dist[v], v);
			}
		}
	}
	cout<<dist[(1<<(n+1))-1];



}