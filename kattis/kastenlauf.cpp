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

void solve() {
	int n;
	cin>>n;
	vii arr(n+2);
	REP(i, n+2) {
		int x,y;cin>>x>>y;
		arr[i] = {x,y};
	}
	bool am[n+2][n+2];
	REP(i, n+2) {
		REP(j, n+2) {
			if (abs(arr[i].first - arr[j].first) +
			 abs(arr[i].second - arr[j].second) <=1000 ) {
				am[i][j] = true;
			} else {
				am[i][j] = false;
			}
		}
	}
	REP(k, n+2) {
		REP(i, n+2) {
			REP(j , n+2) {
				am[i][j] |= (am[i][k] & am[k][j]);
			}
		}
	}
	if (am[0][n+1]) {
		cout<<"happy";
	} else {
		cout<<"sad";
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