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

vi L, H;
vvi adj;
void dfs(int u, int depth) {
	H[u] = L.size();
	L.push_back(depth);
	for (auto v: adj[u]) {
		if (H[v]!=-1) continue;
		dfs(v, depth+1);
		L.push_back(depth);
	}
}

class SparseTable {                              // OOP style
private:
  vi A, P2, L2;
  vector<vi> SpT;                                // the Sparse Table
public:
  SparseTable() {}                               // default constructor

  SparseTable(vi &initialA) {                    // pre-processing routine
    A = initialA;
    int n = (int)A.size();
    int L2_n = (int)log2(n)+1;
    P2.assign(L2_n, 0);
    L2.assign(1<<L2_n, 0);
    for (int i = 0; i <= L2_n; ++i) {
      P2[i] = (1<<i);                            // to speed up 2^i
      L2[(1<<i)] = i;                            // to speed up log_2(i)
    }
    for (int i = 2; i < P2[L2_n]; ++i)
      if (L2[i] == 0)
        L2[i] = L2[i-1];                         // to fill in the blanks

    // the initialization phase
    SpT = vector<vi>(L2[n]+1, vi(n));
    for (int j = 0; j < n; ++j)
      SpT[0][j] = j;                             // RMQ of sub array [j..j]

    // the two nested loops below have overall time complexity = O(n log n)
    for (int i = 1; P2[i] <= n; ++i)             // for all i s.t. 2^i <= n
      for (int j = 0; j+P2[i]-1 < n; ++j) {      // for all valid j
        int x = SpT[i-1][j];                     // [j..j+2^(i-1)-1]
        int y = SpT[i-1][j+P2[i-1]];             // [j+2^(i-1)..j+2^i-1]
        SpT[i][j] = A[x] <= A[y] ? x : y;
      }
  }

  int RMQ(int i, int j) {
    int k = L2[j-i+1];                           // 2^k <= (j-i+1)
    int x = SpT[k][i];                           // covers [i..i+2^k-1]
    int y = SpT[k][j-P2[k]+1];                   // covers [j-2^k+1..j]
    return A[x] <= A[y] ? x : y;
  }
};
int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	int n;
	cin>>n;
	adj.assign(n, vi());
	REP(i, n-1) {
		int u,v;
		cin>>u>>v;
		u--;v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	H.assign(n, -1);
	dfs(0, 0);
	SparseTable tbl(L);
	ll tot = 0;
	REPL(u, 1, n+1) {
		int uind = H[u-1];
		int ulvl = L[uind];
		for (int v = u*2; v<=n;v+=u) {
			int vind = H[v-1];
			int vlvl = L[vind];
			tot += ulvl + vlvl - 2*L[tbl.RMQ(min(vind, uind), max(vind, uind))] +1;
		}
	}
	cout<<tot;
}