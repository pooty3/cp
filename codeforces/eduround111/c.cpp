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
bool possible(vi &a, int idx, int l) {
	if (l>4)return false;
	if (l<3) return true;
	REP(i, (1<<l)) {
		if (__builtin_popcount(i)==3) {
			vi arr;
			int mask = i;
			while (mask) {
				int jj = LSOne(mask);
				arr.push_back(idx + __builtin_ctz(jj));
				mask-=jj;
			}
			if (a[arr[0]]<=a[arr[1]]&& a[arr[1]]<=a[arr[2]]) {
				return false;
			}
			if (a[arr[0]]>=a[arr[1]]&& a[arr[1]]>=a[arr[2]]) {
				return false;
			}
		}
	}
	return true;
}
void solve() {
	int n;
	cin>>n;
	vi arr(n);
	REP(i, n) {
		cin>>arr[i];
	}
	int tot =0;
	REP(i, n) {
		REPL(j, 1, min(5,n-i+1)) {
			if (possible(arr, i, j)) tot++;
		}	
	}cout<<tot<<"\n";
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