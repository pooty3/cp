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

void solve() {
	int n;
	ll p;
	cin>>n>>p;
	vll arr(n);
	set<pair<ll, int>> s;
	ll curtot = (n-1)*p;
	REP(i, n) {
		cin>>arr[i];
		s.insert({arr[i], i});
	}
	bool add[n];
	memset(add, 0, sizeof(add));
	for (auto &[v, idx] : s) {
		if (add[idx]) continue;
		if (v>=p) break;
		int curidx = idx;
		while (true) {
			int nidx = curidx+1;
			if (nidx>=n) break;
			if (add[nidx]) break;
			if (arr[nidx]%v!=0) break;
			add[curidx] = 1;
			curtot -=p;
			curtot += v;
			curidx++;
		}
		curidx =idx;
		while (true) {
			int nidx = curidx-1;
			if (nidx<0) break;
			if (add[nidx]) break;
			if (arr[nidx]%v!=0) break;
			add[curidx] = 1;
			curtot -=p;
			curtot += v;
			curidx--;
		}
	}
	cout<<curtot<<"\n";

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