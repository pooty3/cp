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
	int n;
	cin>>n;
	bool vist[n];
	memset(vist, 0, sizeof(vist));
	ll tot =0;
	vll val(n);
	REP(i, n) {
		int x;
		cin>>x;
		val[i] =x;
		tot+=x;
	}
	priority_queue<ll> pq;
	REP(i, n-1) {
		int u,v;
		cin>>u>>v;u--;v--;
		if (!vist[u]) {
			vist[u] = true;
		} else {
			pq.push(val[u]);
		} 
		if (!vist[v]) {
			vist[v] = true;
		} else {
			pq.push(val[v]);
		} 
	}
	cout<<tot<<" ";
	while (!pq.empty()) {
		tot += pq.top();
		pq.pop();
		cout<<tot<<" ";
	}
	cout<<"\n";
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