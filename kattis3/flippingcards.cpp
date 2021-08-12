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
	int n;
	cin>>n;
	AL.assign(3*n, vi());
	REP(i, n) {
		int u,v;cin>>u>>v;
		AL[i].push_back(n+u-1);
		AL[i].push_back(n+v-1);
	}
	int V = 3*n, Vleft = n;
	unordered_set<int> freeV;
 	 for (int L = 0; L < Vleft; ++L)
    	freeV.insert(L);                             // initial assumption
  	match.assign(V, -1);
  	int MCBM = 0;
  // Greedy pre-processing for trivial Augmenting Paths
  // try commenting versus un-commenting this for-loop
  for (int L = 0; L < Vleft; ++L) {              // O(V+E)
    vi candidates;
    for (auto &R : AL[L])
      if (match[R] == -1)
        candidates.push_back(R);
    if ((int)candidates.size() > 0) {
      ++MCBM;
      freeV.erase(L);                            // L is matched
      int a = rand()%(int)candidates.size();     // randomize this
      match[candidates[a]] = L;
    }
  }                                              // for each free vertex
  for (auto &f : freeV) {                        // (in random order)
    vis.assign(Vleft, 0);                        // reset first
    MCBM += Aug(f);                              // try to match f
  }
  if (MCBM == n) {
  	cout<<"possible\n";
  } else {
  	cout<<"impossible\n";
  }


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