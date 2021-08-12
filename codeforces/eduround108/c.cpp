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
	vvll arr(n, vll());
	vi uarr(n);
	vll sarr(n);
	REP(i, n) {
		cin>>uarr[i];
		uarr[i]--;
	}
	REP(i, n) {
		cin>>sarr[i];
	}
	REP(i, n) {
		arr[uarr[i]].push_back(-sarr[i]);
	}
	vll totarr(n+1, 0);
	REP(i, n) {
		SORT(arr[i]);
		ll cur=0;
		vll parr;
		for (auto v: arr[i]) {
			cur -= v;
			parr.push_back(cur);
		}
		int len = arr[i].size();
		REPL(j,1, len+1) {
			int trunc = (len/j)*j;
			totarr[j]+= parr[trunc-1];
		}
	}
	REPL(i,1,n+1) {
		cout<<totarr[i]<<" ";
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