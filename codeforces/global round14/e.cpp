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


int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	vvi dp((n+1), vi(n+1, 0));
	dp[1][2] = 1;
	dp[2][1] = 1;
	int curx = 2;
	REP(i, n-2) {
		curx++;
		vvi newdp((n+1), vi(n+1, 0));
		REP(u1, curx+1) {
			REP(u2, curx+1) {
				if (dp[u1][u2]==0) continue;
				REPL(j, 1, curx+1) {
				int nu1 = u1 + (j<= u1);
				int nu2 = u2 + (j<=u2);
				if (nu2>nu1&&nu2>j) {
					if (nu2 != max(nu1,j)+1) {
						continue;
					}
				}
				newdp[nu2][j] += dp[u1][u2];
				newdp[nu2][j] %= m;
			}
		}
		dp = newdp;
		cout<<i;
	}
	ll tot =0;
	for (auto [pr, v]:dp) {
		tot += v;
		tot %= m;
	}
	cout<<tot;
}