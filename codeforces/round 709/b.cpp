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
	vi arr(n);
	REP(i, n) {
		cin>>arr[i];
	}
	if (n==1) {
		cout<<0<<"\n";return;
	}
	bool havezero = false;
	int pos=-1;
	int neg=-1;

	REPL(i,1, n) {
		int diff = arr[i] -arr[i-1];
		if (diff ==0) {
			havezero = true;
			if (pos != -1 || neg != -1) {
				cout<<-1<<"\n";return;
			}
		} else {
			if (havezero) {
				cout<<-1<<"\n";return;
			}
		}

		if (diff>0) {

			if (pos != -1 && diff !=pos) {
				cout<<-1<<"\n";return;
			}
			pos = diff;
		}
		if (diff<0) {
			if (neg != -1 && abs(diff) != neg) {
				cout<<-1<<"\n";return;
			}
			neg = abs(diff);
		}
	}
	if (havezero) {
		cout<<0<<"\n";return;
	}
	if (pos == -1 ||  neg == -1){
		cout<<0<<"\n"; return;
	}
	int tot = pos + neg;
	bool able = true;
	REP(i, n) {
		if (arr[i]>= tot) {
			able = false;
			break;
		}
	}
	if (!able) {
		cout<<-1<<"\n";
		return;
	}
	cout<<tot<<" "<<pos<<"\n";

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