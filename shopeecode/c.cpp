#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define SORT(arr) sort(arr.begin(), arr.end())
#define LSOne(S) ((S)&-(S))
#define M_PI 3.1415926535897932384
#define INF 1e12
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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n,k;
	cin>>n>>k;
	vll arr(n);
	REP(i, n) {
		cin>>arr[i];
	}
	vll suffix(n+1,0);
	ll tot =0;
	REP(i, n) {
		tot += arr[n-1-i];
		suffix[n-1-i] = tot;
	}
	vvll dp(n, vll(k, INF));
	REP(i, n) {
		dp[i][0] = (i+1)*(suffix[0]-suffix[i+1]);
	}
	REPL(i,1, k) {
		REPL(j,i, n) {
			dp[j][i] = INF;
			REPL(z,i-1,j-1) {
				dp[j][i] = min(dp[j][i], dp[z][i-1] + (j-z) * (suffix[z] - suffix[j+1]));
			}
		}
	}
	cout<<dp[n-1][k-1];
}