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
	string s;
	cin>>s;
	int prev = -1;
	ll co =0;
	vii sarr;
	REP(i, s.size()) {
		if (s[i]=='?') {

		}
		else {
			if (prev != -1) {
				bool s1 = (i-prev)%2==0;
				bool s2 = s[prev]==s[i];
				if (s1!=s2) {
					sarr.push_back({prev,i});
				}

			} 
			prev = i;
		}
	}
	int cur =0;
	for (auto [x,y]:sarr) {
		ll l = y-cur;
		co += (l*(l+1))/2;
		cur = x+1;
	}
	ll l = s.size()-cur;
	co += (l*(l+1))/2;
	for (auto [x,y]:sarr) {
		ll l = y-x-1;
		co -= (l*(l+1))/2;
	}
	cout<<co<<"\n";

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