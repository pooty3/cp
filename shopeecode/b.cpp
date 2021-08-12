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
	int n,m;
	cin>>n>>m;
	vll bestl(n),bestr(n), tot(n);
	REP(i, n) {
		vll arr(m);
		ll tott =0;
		ll bestll = 0;
		REP(j, m) {
			cin>>arr[j];
			tott += arr[j];
			bestll = max(bestll, tott);
		}
		bestl[i] = bestll;
		tot[i] = tott;
		ll cursuf=0;
		ll bestsuf=0;
		REP(j, m) {
			cursuf += arr[m-1-j];
			bestsuf = max(bestsuf, cursuf);
		}
		bestr[i] = bestsuf;
	}
	vll dpL(n), dpR(n);
	dpL[0] = bestl[0];
	dpR[0] = tot[0];
	REPL(i, 1,n) {
		dpL[i] = max(dpL[i-1] + bestl[i], dpR[i-1] + tot[i]);
		dpR[i] = max(dpR[i-1] + bestr[i], dpL[i-1] + tot[i]);
	}
	cout<<max(dpL[n-1],dpR[n-1])<<"\n";
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