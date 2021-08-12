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

int findmx(vector<string> &arr, char c) {
	vi farr;
	REP(i, arr.size()) {
		int x = 0;
		for(char j:arr[i]) {
			if (j==c) x--;
			else x++;
		}
		farr.push_back(x);
	}
	SORT(farr);
	if (farr[0] >= 0) {
		return 0;
	}
	int curtot =0;
	REP(i, arr.size()) {
		if (curtot + farr[i] >=0) {
			return i;
		}
		curtot += farr[i];
	}return arr.size();
}

void solve() {
	int n;
	cin>>n;
	vector<string> arr(n);
	REP(i, n){
		cin>>arr[i];
	}
	int curmx = 0;
	REP(i, 5) {
		curmx = max(curmx, findmx(arr, (char)('a'+i)));
	}cout<<curmx<<"\n";
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