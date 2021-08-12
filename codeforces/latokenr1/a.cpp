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
int n,m;
bool trysolve(vector<string> &arr, bool par) {
	vector<string> tarr(n, "");
	bool able = true;
	REP(i, n) {
		REP(j, m) {
			if ((i+j)%2==0) {
				tarr[i] += (par? 'W':'R');
			} else {
				tarr[i] += (par?'R':'W');
			}
			if (tarr[i][j]!= arr[i][j] && arr[i][j] != '.') {
				return false;
			}
		}
	}
	if (able) {
		cout<<"YES\n";
	}
	for (string str: tarr) {
		cout<<str<<"\n";
	}
	return true;
}

void solve() {
	cin>>n>>m;
	vector<string> arr(n);
	REP(i, n) {
		cin>>arr[i];
	}
	if ((!trysolve(arr, true)) && (!trysolve(arr, false))) {
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