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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ost;
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
	string s;
	cin>>s;
	map<ii, int> mp;
	vi ans(n, 0);
	int curD = 0;
	int curK = 0;
	REP(i, n) {
		curD += (s[i]=='D');
		curK += (s[i]=='K');
		if (curD ==0 || curK ==0 ) {
			ans[i] = i+1;
		} else {
			int gd = __gcd(curD, curK);
			ii pr = {curD/gd, curK/gd};
			if (mp.find(pr)== mp.end()) {
				mp[pr] = 0;
			} 
			mp[pr]++;
			ans[i] = mp[pr];
		}
	}
	for (auto i: ans) {
		cout<<i<<" ";
	}cout<<"\n";

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