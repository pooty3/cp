#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define SORT(arr) sort(arr.begin(), arr.end())
#define LSOne(S) ((S)&-(S))
#define M_PI 3.1415926535897932384
#define INF 999999
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

void DFS(vvi &arr, bool *b, int i) {
	b[i] = true;
	FOREACH(it, arr[i]) {
		if (!b[*it]) {
			DFS(arr, b, *it);
		}
	}
}
void solve() {
	int m,r;
	cin>>m>>r;
	vvi arr(m, vi());
	bool barr[m];
	memset(barr, 0 , sizeof(barr));
	REP(i, r) {
		int u,v;
		cin>>u>>v;
		arr[u].push_back(v);
		arr[v].push_back(u);
	}
	int tot =0;
	REP(i, m) {
		if (!barr[i]) {
			tot++;
			DFS(arr, barr,i);
		}
	}
	cout<<(tot-1)<<"\n";

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