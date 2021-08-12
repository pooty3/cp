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
	string s;
	cin>>s;
	string ss = s;
	reverse(ss.begin(),ss.end());
	int cc=0;
	int co=0;
	REP(i, n) {
		if (ss[i]!=s[i]) {
			cc++;
		} else if (ss[i]=='0') {
			co++;
		} else {

		}
	}
	cc/=2;
	if (cc>=2) {
		cout<<"ALICE\n";
		return;
	}
	if (cc==0) {
		if (co%2==0 || co == 1) {
			cout<<"BOB\n";
		} else {
			cout<<"ALICE\n";
		}
	} else {
		if (co==1) {
			cout<<"DRAW\n";
		} else {
			cout<<"ALICE\n";
		}
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