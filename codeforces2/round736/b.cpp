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

class SegmentTree {                              // OOP style
private:
  int n;                                         // n = (int)A.size()
  vll A, st, lazy;                                // the arrays

  int l(int p) { return  p<<1; }                 // go to left child
  int r(int p) { return (p<<1)+1; }              // go to right child

  ll conquer(ll a, ll b) {
    if (a == -1) return b;                       // corner case
    if (b == -1) return a;
    return __gcd(a, b);                            // RMQ
  }

  void build(int p, int L, int R) {              // O(n)
    if (L == R)
      st[p] = A[L];                              // base case
    else {
      int m = (L+R)/2;
      build(l(p), L  , m);
      build(r(p), m+1, R);
      st[p] = conquer(st[l(p)], st[r(p)]);
    }
  }


  ll RMQ(int p, int L, int R, int i, int j) {   // O(log n)                         // lazy propagation
    if (i > j) return -1;                        // infeasible
    if ((L >= i) && (R <= j)) return st[p];      // found the segment
    int m = (L+R)/2;
    return conquer(RMQ(l(p), L  , m, i          , min(m, j)),
                   RMQ(r(p), m+1, R, max(i, m+1), j        ));
  }

 

public:
  SegmentTree(int sz) : n(sz), st(4*n), lazy(4*n, -1) {}

  SegmentTree(const vll &initialA) : SegmentTree((int)initialA.size()) {
    A = initialA;
    build(1, 0, n-1);
  }

  ll RMQ(int i, int j) { return RMQ(1, 0, n-1, i, j); }
};
void solve() {
	int n;cin>>n;
	vll arr(n);
	REP(i, n) {
		cin>>arr[i];
	}
	vll diff(n-1);
	bool pos = false;
	REP(i, n-1) {
		diff[i] = abs(arr[i]-arr[i+1]);
		if (diff[i] !=1) {
			pos = true;
		}
	}
	if (!pos) {
		cout<<1<<"\n";return;
	} else {
		int curbs = 1;
		SegmentTree tr(diff);
		int lpointer = 0;
		int rpointer = 0;
		while (true) {
			if (rpointer == n-1) break;
			if (lpointer== rpointer) {
				rpointer++; continue;
			}
			if (tr.RMQ(lpointer, rpointer) == 1) {
				lpointer++;
			} else {
				curbs = max(curbs, rpointer-lpointer+1);
				rpointer++;
			}	
		}
		cout<<curbs+1<<"\n";	
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