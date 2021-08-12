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
	int n,m;
	cin>>n>>m;
	vector<string> v(n);
	vvi arr(n, vi(m,0));
	REP(i, n) {
		cin>>v[i];
	}
	ll tot =0;
	REP(i, n) {
		REP(j, m) {
			arr[i][j] = v[n-1-i][j] == '*' ? 1:0;
			if (arr[i][j]==1 && i!=0&&j>0&&j<m-1) {
				arr[i][j] += min(min(arr[i-1][j], arr[i-1][j-1]),arr[i-1][j+1]);
			}
			tot += arr[i][j];
		} 
	}
	cout<<tot<<"\n";

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