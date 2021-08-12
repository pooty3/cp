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

struct state{
	int possible;
	bool up;
	int mn;
};

state findmin(vector<vector<state>> &dp, vi &arr, int i, int h) {
	if (h<0|| (i==0&&h!=0)) {
		return {0, 0, INF};
	} else if (h==0&&i==0) {
		return {1, 0, 0};
	} else {
		if (dp[i][h].possible ==-1) {
			state s1 = findmin(dp,arr, i-1, h-arr[i-1]);
			state s2 = findmin(dp,arr, i-1, h+arr[i-1]);
			if (s1.possible + s2.possible ==0) {
				dp[i][h] = {0,0,INF};
			} else {
				if (s1.mn< s2.mn) {
					dp[i][h]={1, 1, max(s1.mn, h)};
				} else {
					dp[i][h]={1, 0, max(s2.mn, h)};
				}
			}
		} return dp[i][h];

	}
}

void solve() {
	int m;
	cin>>m;
	vi arr(m);
	REP(i,m) {
		cin>>arr[i];
	}
	vector<vector<state>> dp(m+1, vector<state>(1001, {-1,0,INF}));
	state s = findmin(dp, arr, m, 0);
	int curh =0;
	if (s.possible) {
		vector<char> str(m);
		REP(i, m) {
			str[m-1-i] = s.up? 'U':'D';
			curh += (s.up? -1 :1) * arr[m-1-i];
			s = findmin(dp, arr, m-1-i, curh);
		}
		REP(i, m) {
			cout<<str[i];
		}
	} else {
		cout<<"IMPOSSIBLE";
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