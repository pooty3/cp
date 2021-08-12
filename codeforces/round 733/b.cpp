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

void solve() {
	int h,w;
	cin>>h>>w;
	vvi arr(h, vi(w,0));
	REP(i, w) {
		if (i%2==0) {
			arr[0][i] = 1;
			arr[h-1][i] = 1;
		} 
	}
	REPL(i, 2, h-2) {
		if (i%2==0) {
			arr[i][0] = 1;
			arr[i][w-1] = 1;
		}
	}
	REP(i, h) {
		REP(j,w) {
			cout<<arr[i][j];
		}cout<<"\n";
	}
	cout<<"\n";
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