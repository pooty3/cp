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
	ll x,y,a,b;cin>>x>>y>>a>>b;
	ll bse = min(a,b);
	ll add = abs(a-b);
	ll mn = 0;
	ll mx = min(x,y);
	while (mn<mx) {
		ll md = (mx+mn+1)/2;
		bool able  = true;
		ll bsse = md * bse;
		ll curx = x- bsse;
		ll cury = y - bsse;
		if (curx<0 || cury<0) {
			able = false;
		} else {
			if (add != 0 && md > curx/add + cury/add) {
				able = false;
			}
		}
		if (able) {
			mn = md;
		} else {
			mx = md-1;
		}
	}cout<<mn<<"\n";

}

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	int tc;
	cin>>tc;
	REP(i, tc) {
		solve();
	}

}