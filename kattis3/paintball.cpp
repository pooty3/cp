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
vi match, vis;                                   // global variables
vector<vi> AL;

int Aug(int L) {
  if (vis[L]) return 0;                          // L visited, return 0
  vis[L] = 1;
  for (auto &R : AL[L])
    if ((match[R] == -1) || Aug(match[R])) {
      match[R] = L;                              // flip status
      return 1;                                  // found 1 matching
    }
  return 0;                                      // no matching
}

void solve() {
	int n,m;
	cin>>n>>m;
	AL.assign(2*n, vi());
	match.assign(2*n, -1);
	REP(i,m) {
		int u,v;
		cin>>u>>v;u--;v--;
		AL[u].push_back(v+n);
		AL[v].push_back(u+n);
	}
	int MCBM=0;
	REP(i, n) {
		vis.assign(2*n, 0);
		MCBM += Aug(i);
	}
	//cout<<MCBM;
	if (MCBM == n) {
		REP(i ,n) {
			cout<<match[i+n]+1<<"\n";
		}
	} else {
		cout<<"Impossible\n";
	}
}

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	REP(i, 1) {
		solve();
	}

}