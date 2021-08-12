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


typedef tuple<ll,ll,ll,ll> mv;
void solve() {
	int n;
	cin>>n;
	vll arr(n);
	REP(i, n) {
		cin>>arr[i];
	}
	vector<mv> marr;
	REPL(i, 1, n) {
		if (__gcd(arr[i], arr[i-1])==1) continue;
		ll mpr = min(arr[i], arr[i-1]);
		ll curx = mpr+1;
		while (true) {
			if (__gcd(curx, mpr)==1) {
				if (i==1 || __gcd(arr[i-2], curx)==1) {
					break;
				}
			}
			curx++;

		}
		if (arr[i]>arr[i-1]) {
			marr.push_back({i-1, i, mpr, curx});
			arr[i] = curx;
		} else {
			marr.push_back({i-1,i, curx, mpr});
			arr[i-1] = curx;
		}
	}
	cout<<marr.size()<<"\n";
	for (auto &[i,j,k,l] : marr) {
		cout<<(i+1)<<" "<<(j+1)<<" "<<k<<" "<<l<<"\n";
	}
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