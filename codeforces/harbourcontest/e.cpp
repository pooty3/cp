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
int n;
int findswap(vi& arrayA, vi& arrayB) {
	map<int,int> mp;
	REP(i, n) {
		mp[arrayA[i]] = i;
	}
	bool vis[n];
	memset(vis, 0, sizeof(vis));
	int totswap = 0;
	REP(i,n) {
		if (vis[i]) continue;
		int cur = i;
		int st = i;
		while (true) {
			vis[cur] = true;
			int nval = mp[arrayB[cur]];
			if (nval==st) break;
			totswap++;
			cur = nval;
		}
	}return totswap;
}
void solve() {
	int m;cin>>n>>m;
	vi arr(n);
	vi correct(n, 0);
	REP(i, n) {
		cin>>arr[i];
		arr[i]--;
		int forw = i-arr[i];
		correct[(forw + n)%n]++;
	}
	set<int> ss;
	REP(i, n) {
		if (correct[i]< n-2*m) continue;
		vi aB(n);
		REP(j, n) {
			aB[(i+j)%n]= j;
		}
		if (findswap(arr, aB)<=m) {
			ss.insert(i);
		}
	}
	cout<<ss.size()<<" ";
	for (auto i: ss) {
		cout<<i<<" ";
	}cout<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	/cin.tie(NULL); cout.tie(NULL);
	int tc;
	cin>>tc;
	REP(i, tc) {
		solve();
	}

}