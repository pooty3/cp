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
    return min(a, b);                            // RMQ
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

  void propagate(int p, int L, int R) {
    if (lazy[p] != 0) {                         // has a lazy flag
      st[p] += lazy[p];                           // [L..R] has same value
      if (L != R) {
      	lazy[l(p)] +=  lazy[p];
      	lazy[r(p)] += lazy[p];
      }                                // not a leaf     // propagate downwards
 else {                                      // L == R, a single index
        A[L] += lazy[p];                          // time to update this                              // erase lazy flag
    	}
    	lazy[p] = 0; 
	}
  }

  ll RMQ(int p, int L, int R, int i, int j) {   // O(log n)
    propagate(p, L, R);                          // lazy propagation
    if (i > j) return -1;                        // infeasible
    if ((L >= i) && (R <= j)) return st[p];      // found the segment
    int m = (L+R)/2;
    return conquer(RMQ(l(p), L  , m, i          , min(m, j)),
                   RMQ(r(p), m+1, R, max(i, m+1), j        ));
  }

  void update(int p, int L, int R, int i, int j, ll val) { // O(log n)
    propagate(p, L, R);                          // lazy propagation
    if (i > j) return;
    if ((L >= i) && (R <= j)) {                  // found the segment
      lazy[p] += val;                             // update this
      propagate(p, L, R);                        // lazy propagation
    }
    else {
      int m = (L+R)/2;
      update(l(p), L  , m, i          , min(m, j), val);
      update(r(p), m+1, R, max(i, m+1), j        , val);
      st[p] = conquer(st[l(p)], st[r(p)]);
    }
  }

public:
  SegmentTree(int sz) : n(sz), st(4*n), lazy(4*n, 0) {}

  SegmentTree(const vll &initialA) : SegmentTree((int)initialA.size()) {
    A = initialA;
    build(1, 0, n-1);
  }

  void update(int i, int j, ll val) { update(1, 0, n-1, i, j, val); }

  ll RMQ(int i, int j) { return RMQ(1, 0, n-1, i, j); }
};
void solve() {
	int n;
	cin>>n;
	vll arr;
	vector<pair<ll,int>> prs;
	ll cur =0;
	int cc =0;
	REP(i, n) {
		ll x;
		cin>>x;
		if (x>0) {
			cur+=x;
			arr.push_back(cur);
		} if (x<0) {
			if (arr.size()==0) {
				continue;
			}
			prs.push_back({-x, arr.size()-1});
		}
		if (x>=0) {
			cc++;
		}
	}
	if (arr.size()==0) {
		cout<<cc; return;
	}
	int sz = arr.size();
	SegmentTree seg(arr); 
	SORT(prs);
	for (auto [val, x] : prs) {
		if (seg.RMQ(x,sz-1)>=val) {
			cc++;
			seg.update(x,sz-1, -val);
		}
	}cout<<cc;
	
}

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	int tc=1;
	REP(i, tc) {
		solve();
	}

}