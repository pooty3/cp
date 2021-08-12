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
	int n,m;
	cin>>n>>m;
	vvi adj(n*n, vi());
	vi edges(n*n, 0);
	REP(i, m) {
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		x1--;y1--;x2--;y2--;
		int no1 = x1*n+y1;
		int no2 = x2*n + y2;
		adj[no1].push_back(no2);
		adj[no2].push_back(no1);
		edges[no1]++;
		edges[no2]++;
	}
	set<ii> pq;
	REP(i, n*n) {
		if (edges[i]!=0) {
			pq.insert({edges[i], i});
		}
	}
	int re =0;
	while (m>0) {
		auto &[amt, u] = *pq.rbegin();
		m-=amt;
		re++;
		edges[u] = 0;
		pq.erase(prev(pq.end()));
		FOREACH(it, adj[u]) {
			if (edges[*it]!=0) {
				pq.erase(pq.find({edges[*it], *it}));
				edges[*it]--;
				if (edges[*it]!=0) {
					pq.insert({edges[*it], *it});
				}
			}
		}
	}
	cout<<(n*n-re);


}