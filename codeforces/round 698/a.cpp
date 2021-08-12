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

ll gcd(ll n, ll m) {
	if (n==0) return m;
	return n>m? gcd(m, n):gcd(m%n, n);
}

void solve() {
	int n;
	ll k;
	cin>>n>>k;
	set<ll> s;
	REP(i, n) {
		ll x;
		cin>>x;
		s.insert(x);
	}
	vll diff;
	FOREACH(it, s) {
		if (next(it)==s.end()) {
			break;
		}
		diff.push_back(*next(it) - *it);
	}
	ll curgcd = diff[0];
	REP(i, diff.size()) {
		curgcd = gcd(curgcd, diff[i]);
	}
	if (abs(k - *s.begin())%curgcd==0) {
		cout<<"YES\n";
	} else {
		cout<<"NO\n";
	}

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