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
	cin>>n;
	vll xarr,yarr;
	REP(i, 2*n) {
		ll x,y;
		cin>>x>>y;
		if (x==0) {
			yarr.push_back(abs(y));
		} else {
			xarr.push_back(abs(x));
		}
	}
	SORT(yarr);
	SORT(xarr);
	double dist=0;
	REP(i, n) {
		dist += sqrt(xarr[i]*xarr[i] + yarr[i] * yarr[i]);
	}
	cout<<setprecision(10)<<dist<<"\n";

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