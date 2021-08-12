#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define SORT(arr) sort(arr.begin(), arr.end())
#define LSOne(S) ((S)&-(S))
#define M_PI 3.1415926535897932384
#define INF 999999999999999
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
	vector<vii> adj(3*n, vii());
	vvll apsp(3*n, vll(3*n, INF));
	REP(i, 3) {
		REP(j, n-1) {
			int x;
			cin>>x;
			int no1 = n*i + j;
			adj[no1].push_back({no1+1, x});
			adj[no1+1].push_back({no1, x});
			apsp[no1][no1+1] = x;
			apsp[no1+1][no1] = x;
		}
	}
	REP(i, 2) {
		REP(j, n) {
			int x;
			cin>>x;
			int no1 = n*i + j;
			adj[no1].push_back({no1+n, x});
			adj[no1+n].push_back({no1, x});
			apsp[no1][no1+n] = x;
			apsp[no1+n][no1] = x;
		}
	}
	REP(i, 3*n) {
		apsp[i][i] = 0;
	}
	REP(k, 3*n) {
		REP(i, 3*n) {
			REP(j, 3*n) {
				apsp[i][j] = min(apsp[i][j], apsp[i][k] + apsp[k][j]);
			}
		}
	}
	set<int> s;
	REP(i,m) {
		int r,c;
		cin>>r>>c;r--;c--;
		int no = r*n + c;
		s.insert(no);
	}
	FOREACH(it, s) {
		FOREACH(it2, s) {
			cout<<apsp[*it][*it2]<<" ";
		}cout<<"\n";
	}
	ll cost=0;
	priority_queue<ii> pq;
	pq.push({0,*s.begin()});
	while (!pq.empty()) {
		if (s.empty()) {
			break;
		}
		auto [w, u] = pq.top();
		if (s.find(u)==s.end()) {
			continue;
		}
		s.erase(u);
		pq.pop();
		cost -= w;
		FOREACH(it, s) {
			pq.push({-apsp[u][*it], *it});
		}
	}
	cout<<cost;
}