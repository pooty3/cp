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
int fac = 40000;
ll keyfunc(ll cc, ll mm) {
	return cc*fac + mm;
}
map<ll, ld> dp;
ld expect(int cc, int mm, int vv) {
	if (dp.find(keyfunc(cc, mm)) == dp.end()) {;
		ld val = (ld)(fac-cc-mm)/fac;
		if (cc != 0) {
			int nmm = mm == 0 ? 0 : min(cc,vv)/2 + mm;
			val += (ld)cc/fac * (1 + expect(cc - min(cc, vv), nmm, vv));
		}
		if (mm != 0) {
			int ncc = cc == 0 ? 0 : min(mm,vv)/2 + cc;
			val += (ld)mm/fac * (1 + expect(ncc, mm- min(mm, vv) , vv));
		}
		dp.insert({keyfunc(cc, mm), val});
	} return dp[keyfunc(cc,mm)];
}
void solve() {
	ld c,m,p,v;
	cin>>c>>m>>p>>v;
	dp.clear();
	int cc = round(c*fac);
	int mm = round(m * fac);
	int vv = round(v* fac);
	cout<<setprecision(7)<<expect(cc, mm, vv)<<"\n";

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