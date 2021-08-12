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
	vll arrc(n);
	vll arra(n);
	vll arrb(n);
	vll arrd(n);
	REP(i, n) {
		cin>>arrc[i];
	}
	REP(i, n) {
		cin>>arra[i];
	}
	REP(i, n) {
		cin>>arrb[i];
	}
	REP(i, n) {
		arrd[i] = abs(arrb[i]-arra[i]);
	}
	vll barr(n, 0);
	barr[n-1] = arrc[n-1]+1;
	for (int i = n-2; i>=1; i--) {
		if (arrd[i+1]==0) {
			barr[i] = 0;
		} else {
			barr[i] = max(barr[i+1], arrd[i+1]);
		}
		barr[i] += (1+ arrc[i] -  arrd[i+1] );
	}
	ll curmax = 0;
	REP(i, n-1) {
		curmax = max(curmax, barr[i+1]+ arrd[i+1]);
	}
	cout<<curmax<<"\n";

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