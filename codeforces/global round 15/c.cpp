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
bool inter(vii &arr, int ind1, int ind2) {
	int val =0;
	vi chk = {arr[ind2].first, arr[ind2].second};
	REP(i, 2) {
		if (chk[i]>arr[ind1].first && chk[i]< arr[ind1].second) val++;
	}
	return (val == 1);
}
void solve() {
	int n,k;
	cin>>n>>k;
	vii arr(k);
	set<int> taken;
	REP(i, k) {
		int u,v;
		cin>>u>>v;
		u--;
		v--;
		if (u<v) {
			arr[i] = {u,v};
		} else {
			arr[i] = {v,u};
		}taken.insert(u);
		taken.insert(v);
	}
	vi barr;
	REP(i, 2*n) {
		if (taken.find(i)==taken.end()) {
			barr.push_back(i);
		}
	}
	REP(i, n-k) {
		arr.push_back({barr[i], barr[i+n-k]});
	}
	int tot =0;
	REP(i, n) {
		REPL(j,i+1, n) {
			if (inter(arr, i, j))tot++;
		}
	}cout<<tot<<"\n"
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