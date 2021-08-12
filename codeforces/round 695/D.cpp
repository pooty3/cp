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

int main()
{
	ll mood = 1e9+7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n,k,q;
	cin>>n>>k>>q;
	vvll dp(k+1, vll(n, 1));
	vll arr(n);
	REP(i, n) {
		cin>>arr[i];
	}
	REPL(i,1, k+1) {
		REP(j, n) {
			dp[i][j] = 0;
			if (j > 0) {
				dp[i][j]+= dp[i-1][j-1];
			}
			if (j < n-1) {
				dp[i][j] += dp[i-1][j+1];
			}
			dp[i][j] %= mood;
		}
	}
	REP(i, k+1) {
		REP(j, n) {
			cout<<dp[i][j];
		}
		cout<<"\n";
	}
	vll carr(n, 0);
	ll curtot=0;
	REP(i, n) {
		REP(j, k+1) {
			carr[i] += dp[j][i];
			carr[i] %= mood;
			curtot += (dp[j][i] * arr[i])%mood;
			curtot %= mood;
		}
	}
	REP(i, n) {
		cout<<carr[i];
	}
	REP(i, q) {
		int v;
		ll ne;
		cin>>v>>ne;
		v--;
		curtot -= (arr[v]*carr[v])%mood;
		curtot += (ne*carr[v])%mood;
		if (curtot < 0) {
			curtot += mood;
		}
		curtot %= mood;
		arr[v] = ne;
		cout<<curtot<<"\n";
	}


}