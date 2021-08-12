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

ll solve(vll &arr, int top, int bot, vvll &dp) {
	if (dp[bot][top] == -1) {
		if (top == bot) {
			dp[bot][top] = 0;
		} else {
			dp[bot][top] = arr[top]-arr[bot]+
			min(solve(arr, top-1, bot, dp), solve(arr, top, bot+1, dp));
		}
	}return dp[bot][top];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin>>n;
	vll arr(n);
	REP(i,n) {
		cin>>arr[i];
	}
	SORT(arr);
	int bot =0, top = n-1;
	vvll dp(n, vll(n,-1));
	cout<<solve(arr, n-1, 0, dp);


}