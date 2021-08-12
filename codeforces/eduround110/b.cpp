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
	int n;
	cin>>n;
	map<int, vi> mp;
	REP(i, n) {
		int x;
		cin>>x;
		int y = x;
		int c =0;
		while (y%2==0) {
			c++;
			y/=2;
		}
		if (mp.find(c)==mp.end()) {
			mp.insert({c, vi()});
		}
		mp[c].push_back(x);
	}
	vi arr;
	for (auto it = mp.rbegin(); it != mp.rend(); it++) {
		vi &parr = it->second;
		for (auto x:parr) {
			arr.push_back(x);
		}
	}
	int cc = 0;
	REP(i, n) {
		REPL(j, i+1, n) {
			if (__gcd(arr[i], 2*arr[j]) >1) {
				cc++;
			}
		}
	}
	cout<<cc<<"\n";
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