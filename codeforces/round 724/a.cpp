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

int alive(vi &arr, int idx) {
	if (idx<0||idx>=arr.size()) return 0;
	return arr[idx];
}
void solve() {
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	vi arr(n);
	REP(i,n) {
		arr[i]= s[i]-'0';
	}
	REP(i, m) {
		bool changed = false;
		vi narr = arr;
		REP(j, n) {
			if (arr[j]==1) continue;
			if (alive(arr, j-1) + alive(arr, j+1)==1) {
				narr[j] = 1;
				changed = true;
			}
		}
		arr = narr;
		if (!changed) break;
	}
	for (auto i: arr) {
		cout<<i;
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