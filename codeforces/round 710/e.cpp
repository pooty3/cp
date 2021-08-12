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
	vi marr(n), larr(n);
	int bf = marr[0] = larr[0] = arr[0];
	set<int> mnumbers, lnumbers;
	REPL(i,1, bf) {
		mnumbers.insert(i);
		lnumbers.insert(i);
	}
	REPL(i, 1, n) {
		if (arr[i] != bf) {
			marr[i] = larr[i] = arr[i];
			REPL(j, bf+1, arr[i]) {
				mnumbers.insert(j);
				lnumbers.insert(j);
			}
			bf = arr[i];
		} else {
			marr[i] = *mnumbers.rbegin();
			mnumbers.erase(mnumbers.find(marr[i]));
			larr[i] = *lnumbers.begin();
			lnumbers.erase(lnumbers.begin());
		}
	}
	for (auto i: larr) {
		cout<<i<<" ";
	}cout<<"\n";
	for (auto i: marr) {
		cout<<i<<" ";
	}cout<<"\n";

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