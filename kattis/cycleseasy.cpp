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


ll ways(vvll &dp, set<ii> &s, int mask, int sind) {
	if (dp[sind][mask]==-1) {
		if (mask==0) {
			if (s.find({0, sind})!=s.end()) {
				dp[sind][mask] =0;
			} else {
				dp[sind][mask]=1;
			}
		} else {
			ll wy=0;
			int m = mask;
			while(m) {
				int l = LSOne(m);
				int ind = __builtin_ctz(l)+1;
				if (s.find({sind, ind})==s.end()) {
					wy += ways(dp, s,mask^l, ind);
				}
				m -= l;
			}
			dp[sind][mask] = wy;
		}
	}
	return dp[sind][mask];

}

void solve(int tc) {
	int n,k;
	cin>>n>>k;
	set<ii> mp;
	REP(i, k) {
		int u,v;
		cin>>u>>v;
		mp.insert({u-1,v-1});
		mp.insert({v-1,u-1});
	}
	vvll dp(n, vll(1<<(n-1), -1));	
	ll wy = ways(dp, mp, (1<<(n-1))-1, 0)/2;
	printf("Case #%d: %d\n", tc, wy%9901);

}

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	int tc;
	cin>>tc;
	REP(i, tc) {
		solve(i+1);
	}

}