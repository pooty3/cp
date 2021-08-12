#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
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
	bool barr[2*n+1];
	memset(barr, 0, sizeof(barr));
	vi arr(n);
	REP(i, n) {
		cin>>arr[i];
		barr[arr[i]] = true;
	}
	int unable =0;
	int counter = 0;
	REPL(i,1, 2*n+1) {
		if (barr[i]) {
			if (counter==0) {
				unable++;
			} else {
				counter--;
			}
		} else {
			counter++;
		}
	}
	counter =0;
	for(int i = 2*n; i >0 ; i--) {
		if (barr[i]) {
			if (counter==0) {
				unable++;
			} else {
				counter--;
			}
		} else {
			counter++;
		}

	}
	cout<<(n-unable+1)<<"\n";

}

int main()
{
	int tc;
	cin>>tc;
	REP(i, tc) {
		solve();
	}


}