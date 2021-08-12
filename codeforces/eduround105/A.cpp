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
	string str;
	cin>>str;
	char sc = str[0];
	char ec = str[str.length()-1];
	if (sc == ec) {
		cout<<"NO\n";
		return;
	}
	int num =0;
	bool possible = true;
	REP(i, str.size()) {
		if (str[i]==sc) {
			num++;
		} else if (str[i]==ec) {
			num--;
		} else {
			num++;
		}
		if (num <0) {
			possible = false;
			break;
		}
	}
	if (possible&& num==0) {
		cout<<"YES\n";
		return;
	}
	num =0;
	possible = true;
	REP(i, str.size()) {
		if (str[i]==sc) {
			num++;
		} else if (str[i]==ec) {
			num--;
		} else {
			num--;
		}
		if (num <0) {
			possible = false;
			break;
		}
	}
	if (possible&& num==0) {
		cout<<"YES\n";
		return;
	}
	cout<<"NO\n";
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