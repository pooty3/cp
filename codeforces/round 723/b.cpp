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
vi dp(10000,-1);
int able(ll n) {
	if (n==0) {
		return 1;
	}
	if (n<0) {
		return 0;
	}
	if (dp[n]==-1) {
		if (able(n-11)==1 || able(n-111)==1) {
			dp[n] = 1;
		} else {
			dp[n] =0;
		}
	}
	return dp[n];
}
void solve() { 
	ll n;
	cin>>n;
	if (n>= 11*111) {
		cout<<"YES\n"; return;
	}
	cout<<(able(n) ==1 ? "YES":"NO")<<"\n";

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