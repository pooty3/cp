#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define SORT(arr) sort(arr.begin(), arr.end())
#define LSOne(S) ((S)&-(S))
#define M_PI 3.1415926535897932384
#define INF 1e9+7
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
	int n,m,k;
	cin>>n>>m>>k;
	vector<vii> arr(n*m, vii());
	REP(i, n) {
		REP(j, m-1) {
			int x;
			cin>>x;
			arr[i*m+j].push_back({i*m+j+1,x});
			arr[i*m+j+1].push_back({i*m+j,x});
		}
	}
	REP(i, n-1) {
		REP(j, m) {
			int x;
			cin>>x;
			arr[i*m + j].push_back({i*m+j+m, x});
			arr[i*m+j+m].push_back({i*m+j,x});
		}
	}
	if (k%2 ==1) {
		REP(i, n) {
			REP(j, m) {
				cout<<-1<<" ";
			}cout<<"\n";
		}return 0;
	} 
	vvi dp(n*m, vi(k/2+1, 0));
	REPL(kk, 1, k/2+1) {
		REP(i, n*m) {
			int cur = INF;
			for (auto [v, w]: arr[i]) {
				cur = min(cur, dp[v][kk-1] + w);
			}
			dp[i][kk] = cur;
		}

	}
	REP(i, n) {
		REP(j,m) {
			cout<<dp[i*m+j][k/2]*2<<" ";
		}cout<<"\n";
	}

}