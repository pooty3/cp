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
	vi arr(n);
	REP(i, n) {
		cin>>arr[i];
	}
	int tot =0;
	bool barr[n];
	memset(barr, 0, sizeof(barr));
	REPL(i,1, n-1) {
		if (arr[i]< arr[i-1] && arr[i]<arr[i+1]) {
			barr[i] = 1;
			tot ++;
		} else if (arr[i] > arr[i-1] && arr[i] > arr[i+1]) {
			barr[i] = 1;
			tot++;
		}else {}
	}
	int ntot = tot;
	REPL(i, 1, n-1) {
		int prev = arr[i];
		int cur = barr[i] + barr[i-1] +barr[i+1];
		arr[i] = arr[i-1];
		int cval =0, cval2=0;
		if (i < n-2) {
			if((arr[i+1] < arr[i] && arr[i+1]< arr[i+2])||
				(arr[i+1] > arr[i] && arr[i+1]> arr[i+2])) {
				cval = 1;
			}
		}
		arr[i] = arr[i+1];
		if (i > 1) {
			if((arr[i-1] < arr[i] && arr[i-1]< arr[i-2])||
				(arr[i-1] > arr[i] && arr[i-1]> arr[i-2])) {
				cval2 = 1;
			}
		}
		int curtot = tot;
		curtot-=cur;
		curtot += min(cur, min(cval, cval2));
		ntot = min(ntot, curtot);
		arr[i] = prev;
	}
	cout<<ntot<<"\n";

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