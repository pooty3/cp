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

void solve() {
	ll n;
	vll tok;
	cin>>n;
	ll cur=2;
	while (cur < n) {
		tok.push_back(cur);
		cur = cur*cur;
	}
	tok.push_back(n);
	cout<<(n+tok.size()-3)<<"\n";
	REPL(i, 3, n) {
		ll z = *lower_bound(tok.begin(), tok.end(), i);
		if (z!=i) {
			cout<<i<<" "<<z<<"\n";
		}
	}
	for (int i = tok.size()-1; i>0; i--) {
		cout<<tok[i]<<" "<<tok[i-1]<<"\n";
		cout<<tok[i]<<" "<<tok[i-1]<<"\n";
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