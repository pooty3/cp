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
vi dp(1000001,0);
void solve(int ts) {
	int n;cin>>n;
	cout<<"Case #"<<ts<<": "<<dp[n]<<"\n";
}

int main()
{
	vi dpA(1000001,0);
	dpA[1] =0;
	REPL(i,2, 1000001) {
		int curmx = 1;
		REPL(j, 2, i) {
			if (j*j>i) break;
			if (i%j==0) {
				curmx = max(curmx, 1 + dpA[i/j - 1]);
				curmx = max(curmx, 1 + dpA[j - 1]);
			}
		}
		dpA[i] = curmx;
	}
	REPL(i, 3,1000001) {
		int curmx = 1;
		REPL(j, 3, i) {
			if (j*j>i) break;
			if (i%j==0) {
				curmx = max(curmx, 1 + dpA[i/j - 1]);
				curmx = max(curmx, 1 + dpA[j - 1]);
			}
		}
		dp[i] = curmx;
	}
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int tc;
	cin>>tc;
	REP(i, tc) {
		solve(i+1);
	}

}