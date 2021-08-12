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
	int n,m;cin>>n>>m;
	vector<set<int>> arr(n, set<int>());
	int cur0 = n;
	REP(i, m) {
		int u,v;cin>>u>>v;
		u--;v--;
		if (u>v) {
			swap(u,v);
		}
		arr[u].insert(v);
		if (arr[u].size()==1) {
			cur0--;
		}
	}
	int q;
	cin>>q;
	REP(i, q) {
		int ind;cin>>ind;
		if (ind == 1) {
			int u,v; cin>>u>>v;
			u--;v--;
			if (u>v) {
				swap(u,v);
			}
			arr[u].insert(v);
			if(arr[u].size()==1) {
				cur0--;
			}
		} else if (ind == 2) {
			int u,v; cin>>u>>v;
			u--;v--;
			if (u>v) {
				swap(u,v);
			}
			arr[u].erase(v);
			if (arr[u].size()==0) {
				cur0++;
			}
		} else {
			cout<<cur0<<"\n";
		}
	}
}

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	int tc =1;
	REP(i, tc) {
		solve();
	}

}