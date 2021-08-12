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
	ll k;cin>>n>>k;
	if (n < 64 && k > (1LL<<(n-1))) {
		cout<<-1<<"\n";
		return;
	}
	k--;
	vi arr(63);
	REP(i, 63) {
		if ( (1LL<<i)&k) {
			arr[i] = 1;
		} else {
			arr[i] = 0;
		}
	}
	int farr[n];
	REP(i, n) {
		farr[i] = i+1;
	}
	int cur1 = -1; 
	REP(i, 63) {
		if (arr[i] == 0 && cur1 != -1) {
			reverse(farr+n-i-1, farr+n-cur1);
			cur1 =-1;
		}
		if (arr[i] == 1 && cur1 == -1) {
			cur1 = i;
		}
	}
	for (int i: farr) {
		cout<<i<<" ";
	}cout<<"\n";


}

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	int tc;
	cin>>tc;
	REP(i, tc) {
		solve();
	}

}