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
typedef vector<vector<ii>> vvii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int l,w;cin>>l>>w;
	vvi dp(l+1, vi(w+1, -1));
	dp[0][0] = 0;
	REPL(i,1,l+1) {
		REP(j, w+1) {
			REPL(z,1, 27) {
				if (j-z<0)break;
				if (dp[i-1][j-z]!=-1) {
					dp[i][j] = z;break;
				}
			}
		}
	}
	if (dp[l][w]==-1) {
		cout<<"impossible\n";
	} else {
		string s= "";
		int cur =w;
		REP(i, l) {
			s = (char)(dp[l-i][cur]+'a'-1)+s;
			cur -= dp[l-i][cur];
		}cout<<s;

	}
}