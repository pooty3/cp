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

ll md = 1e9+7;
vll facts;
vll invfacts;
ll modPow(ll b, ll p) {
	if (p==0) return 1;
	if (p%2==1) return (modPow(b, p-1)*b)%md;
	ll val = modPow(b, p/2);
	return (val*val)%md;
}
ll modInverse(ll b) {
	return modPow(b, md-2);
}
ll nCr(ll n, ll r) {
	if (r < 0) return 0;
	if (r > n) return 0;
	return (((facts[n]*invfacts[r])%md)*invfacts[n-r])%md;
}
void solve() {
	int n,l,r;
	cin>>n>>l>>r;
	int start = min(r-n, 1-l);
	ll curtot = (start * nCr(n, n/2))%md;
	if (n%2==1) {
		curtot *= 2;
		curtot %= md;
	}
	int fixedminus = 0;
	int fixedadd = 0;
	while (true) {
		start++;
		if (n-fixedminus+start > r) {
			fixedminus++;
		}
		if (1-start+fixedadd<l) {
			fixedadd++;
		}
		if (fixedminus+fixedadd > n) {
			break;
		}
		curtot += nCr(n-fixedminus-fixedadd, n/2-fixedminus);
		curtot %=md;
		if (n%2==1) {
			curtot += nCr(n-fixedminus-fixedadd, n/2+1-fixedminus);
			curtot %=md;
		}
	}cout<<curtot<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	facts.push_back(1);
	REPL(i,1, 200005) {
		facts.push_back((facts[i-1]*i)%md);
	}
	for (auto i: facts) {
		invfacts.push_back(modInverse(i));
	}
	int tc;
	cin>>tc;
	REP(i, tc) {
		solve();
	}

}