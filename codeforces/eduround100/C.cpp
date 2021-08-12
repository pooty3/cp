#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
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

ll findlocation(map<ll,ll> &mp, int t) {
	auto it = mp.lower_bound(t);
	ll t2 = it->first;
	ll x2 = it->second;
	if (t==t2) {
		return x2;
	} else {
		it = prev(it);
		ll t1 = it->first;
		ll x1 = it->second;
		return x1 + (x2-x1)/(t2-t1) * (t-t1);
	}
}

void solve() {
	int cmd;
	cin>>cmd;
	int tot =0;
	bool right = true;
	ll stoptime =0;
	ll curpos =0;
	ll prevtime =0;
	ll prevloc = 0;
	REP(i, cmd) {
		ll t,x;
		cin>>t>>x;
		ll maxpos = (min(stoptime, t) - prevtime) * (right ? 1 :-1) + curpos;
		if (prevloc >= min(maxpos, curpos) && prevloc <= max(maxpos, curpos)) {
			tot ++;
		}
		prevtime = t;
		prevloc = x;
		curpos = maxpos;
		if (stoptime <= t) {
			stoptime = t + abs(x-curpos);
			right = x >curpos;
		}

	}
	ll maxpos = (stoptime-prevtime)*(right ? 1 :-1) + curpos;
	if (prevloc >= min(maxpos, curpos) && prevloc <= max(maxpos, curpos)) {
		tot ++;
	}
	tot--;
	cout<<tot<<"\n";

}

int main()
{
	int tc;
	cin>>tc;
	REP(i, tc) {
		solve();
	}

}