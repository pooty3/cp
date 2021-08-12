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
ll lcm(ll a, ll b) {
	return (a / __gcd(a,b)) * b;
}
void solve() {
	ll n;
	cin>>n;
	int curno = 2;
	ll curlcm = 1;
	ll tot =0;
	while (curlcm <= n) {

		ll tot1 = n/curlcm;
		ll tot2 = n/lcm(curlcm, curno);
		tot += (tot1 - tot2) * curno;
		tot %= md;
		curlcm = lcm(curlcm, curno);
		curno++;

	}
	cout<<tot<<"\n";

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