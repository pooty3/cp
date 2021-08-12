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

ll md = 1e9 + 7;

vvll dp(1001, vll(1001,-1));
void solve() {
	int n,k;
	cin>>n>>k;
	map<int,int> mp;
	REP(i, n) {
		int v;
		cin>>v;
		if (mp.find(v)==mp.end()) {
			mp.insert({v,0});
		}
		mp[v]++;
	}
	ll curtot =1;
	int need = k;
	for (auto it = mp.rbegin(); it!= mp.rend(); it++) {
		int v = it->second;
		if (v>= need) {
			cout<<dp[v][need]<<"\n";
			break;
		}
		need-=v;
	}
}

int main()
{
	REPL(i,1, 1001) {
		REP(j, 1001) {
			if (j==0||i==j) {
				dp[i][j] = 1;
			} else if (j<i) {
				dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%md;
			}
		}
	}
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int tc;
	cin>>tc;
	REP(i, tc) {
		solve();
	}

}