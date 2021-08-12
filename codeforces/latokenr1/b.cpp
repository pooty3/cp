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
	int n;
	cin>>n;
	vll arr(n+2);
	arr[0] = 0;
	arr[n+1] = 0;
	REPL(i,1,n+1){
		cin>>arr[i];
	}
	vll farr = arr;
	ll excess=0;
	REPL(i, 1, n+1) {
		if (farr[i]> farr[i-1] && farr[i]>farr[i+1]) {
			excess += farr[i] - max(farr[i+1], farr[i-1]);
			farr[i] = max(farr[i+1], farr[i-1]);
		}
	}
	REPL(i, 1, n+2) {
		excess += abs(farr[i]-farr[i-1]);
	}
	cout<<excess<<"\n";

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