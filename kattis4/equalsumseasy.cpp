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
int css=0;
void solve() {
	css++;
	printf("Case #%d:\n", css);
	int n;cin>>n;vi arr(n);
	REP(i, n) {
		cin>>arr[i];
	}
	map<int, int> mp;
	REPL(i, 1,(1<<n)) {
		int cur =0;
		REP(j, n) {
			if (i&(1<<j)) {
				cur += arr[j];
			}
		}
		if (mp.find(cur)!=mp.end()) {
			REP(j, n) {
				if ((1<<j)&mp[cur]) {
					cout<<arr[j]<<" ";
				}
			}cout<<"\n";
			REP(j, n) {
				if ((1<<j)&i) {
					cout<<arr[j]<<" ";
				}
			}cout<<"\n";return;
		}
		mp[cur] = i;
	}
	cout<<"Impossible\n";

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