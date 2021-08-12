#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define SORT(arr) sort(arr.begin(), arr.end())
#define LSOne(S) ((S)&-(S))
#define M_PI 3.1415926535897932384
#define INF 99999999
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

ii cst(vector<vii> &dp, vi &cost, int step, int ind) {
	if (ind<0||ind >=dp.size()||step < 1||step>=dp.size()) {
		return {0,INF};
	} else {
		if (dp[ind][step].first == -1) {
			ii p1 = cst(dp, cost, step-1, ind-step);
			ii p2 = cst(dp, cost, step, ind + step);
			if (p1.first+p2.first ==0) {
				dp[ind][step] = {0,INF};
			} else {
				dp[ind][step] = {1, cost[ind]+min(p1.second, p2.second)};
			}

		}return dp[ind][step];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin>>n;
	vector<vii> arr(n, vii(n, {-1, INF}));
	vi cost(n);
	REP(i, n) {
		cin>>cost[i];
	}
	arr[1][1] = {1,cost[1]};
	int mn = INF;
	REPL(i,1, n) {
		mn = min(mn, cst(arr, cost, i, n-1).second);
	}
	cout<<mn;


}