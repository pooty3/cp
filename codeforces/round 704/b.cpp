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
	vi narr;
	REP(i, n) {
		cin>>arr[i];
	}
	set<int> left;
	REP(i, n) {
		left.insert(i+1);
	}
	int cur = n-1;
	int curdone = n;
	int curmax = n;
	while (cur >= 0) {
		if (curmax == arr[cur]) {
			REPL(i, cur, curdone) {
				narr.push_back(arr[i]);
				left.erase(left.find(arr[i]));
			}
			if (left.size()>0) {
				curmax = *left.rbegin();
			}
			curdone = cur;
		} 
		cur--;
	}
	REP(i, n) {
		cout<<narr[i]<<" ";
	}
	cout<<"\n";

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