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
	int able = false;
	int n;
	vi sarr(4);
	cin>>n;
	cin>>sarr[0]>>sarr[3]>>sarr[2]>>sarr[1];
	REP(i, 16) {
		vi minarr(4,0), maxarr(4,n);
		REP(j, 4) {
			if (i &(1<<j)) {
				minarr[j]++;
				minarr[(j+3)%4]++;
			}else {
				maxarr[j]--;
				maxarr[(j+3)%4]--;
			}

		}

		bool able2 = true;
		REP(j, 4) {
			if (sarr[j] < minarr[j] || maxarr[j] < sarr[j]){
				able2= false;
				break;
			}
		}
		if (able2) {
			able = true;
			break;
		}
	}
	if (able) {
		cout<<"YES\n";
	} else {
		cout<<"NO\n";
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