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
	int n,m;
	cin>>n>>m;
	vi ccount(n,0);
	vi asg(m, -1);
	vvi arr(m, vi());
	REP(i, m) {
		int x;
		cin>>x;
		REP(z, x) {
			int y;cin>>y;y--;
			arr[i].push_back(y);
		}
		if (x==1) {
			ccount[arr[i][0]]++;
			asg[i] = arr[i][0];
		}
	}
	bool able = true;
	REP(i, n) {
		if (ccount[i]> (m+1)/2) {
			cout<<"NO\n";return;
		}
	}
	cout<<"YES\n";
	REP(i, m) {
		if (asg[i] == -1) {
			int y = arr[i][0];
			if (ccount[y]+1 > (m+1)/2) {
				asg[i] = arr[i][1];
				ccount[arr[i][1]]++;
			} else {
				asg[i] = y;
				ccount[y]++;
			}
		}
	}
	for (int i: asg) {
		cout<<(i+1)<<" ";
	}cout<<"\n";

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