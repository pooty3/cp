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

bool possible(vvi &dp, vi &arr, int i, int w) {
	if (w==0) return true;
	if (w<0 || i<0) return false;
	if (dp[i][w]==-1) {
		dp[i][w] = possible(dp, arr, i-1, w) || possible(dp, arr, i-1, w-arr[i]);
	}
	return dp[i][w];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin>>n;
	vi arr(n);
	REP(i, n) {
		cin>>arr[i];
	}
	vvi dp (n, vi(2001, -1));
	int offset =0;
	while (true) {
		if (possible(dp, arr, n-1,offset+1000)) {
			cout<<(offset+1000);
			break;
		}
		if (possible(dp, arr, n-1, 1000-offset)) {
			cout<<(1000-offset);
			break;
		}

		offset++;
	}

}