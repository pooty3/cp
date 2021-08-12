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

ii possible(vector<vii> &memo, vi &parr, int val, int ind) {
	if (val == 0) {
		return {1, 0};
	} else if (val <0||ind < 0) {
		return {0, 0};
	} else if (memo[val][ind].first == -1) {
		int curmin = INF;
		REP(i, ind+1) {
			ii p = possible(memo, parr, val - parr[i], i-1);
			if (p.first==1) {
				curmin = min(curmin, p.second+1);
			}
		}
		if (curmin==INF) {
			memo[val][ind] = {0,0};
		} else {
			memo[val][ind] = {1, curmin};
		}
	}
	return memo[val][ind];
}
void solve() {
	int p;
	cin>>p;
	int n;
	cin>>n;
	vi arr(n);
	REP(i, n) {
		cin>>arr[i];
	}
	vector<vii> dp(20001, vii(n, {-1, 0}));
	while (true) {
		ii pa = possible(dp, arr, p, n-1);
		if (pa.first == 1) {
			cout<<p<<" "<<pa.second<<"\n";
			break;
		} 
		p++;
	}



}

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	int tc;
	cin>>tc;
	REP(i, tc) {
		solve();
	}

}