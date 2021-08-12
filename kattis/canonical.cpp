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
	vi dp(arr[n-1]+arr[n-2]);
	bool canonical = true;
	REP(i, arr[n-1]+ arr[n-2]) {
		int mi = i;
		REPL(j, 1,  n) {
			if (i < arr[j]) break;
			mi = min(dp[i-arr[j]]+1, mi);
		}
		dp[i] = mi;
		int greed =0;
		int left =i;
		REP(j, n) {
			greed += left/arr[n-1-j];
			left %= arr[n-1-j];
		}
		if (mi != greed) {
			canonical = false;
			break;
		}

	}
	if (!canonical){
		cout<<"non-";
	}
	cout<<"canonical";
}