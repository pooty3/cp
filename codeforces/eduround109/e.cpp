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
  vi A, st, lazy;                                // the arrays

  int l(int p) { return  p<<1; }                 // go to left child
  int r(int p) { return (p<<1)+1; }              // go to right child

  int conquer(int a, int b) {
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
      if (L != R){                                // not a leaf
        lazy[l(p)] += lazy[p]; 
        lazy[r(p)] += lazy[p]; 
      }  // propagate downwards
      else  {                                     // L == R, a single index
        A[L] += lazy[p];
        }                          // time to update this
      lazy[p] = 0;                              // erase lazy flag
    }
  }

  int RMQ(int p, int L, int R, int i, int j) {   // O(log n)
    propagate(p, L, R);                          // lazy propagation
    if (i > j) return -1;                        // infeasible
    if ((L >= i) && (R <= j)) return st[p];      // found the segment
    int m = (L+R)/2;
    return conquer(RMQ(l(p), L  , m, i          , min(m, j)),
                   RMQ(r(p), m+1, R, max(i, m+1), j        ));
  }

  void update(int p, int L, int R, int i, int j, int val) { // O(log n)
    propagate(p, L, R);                          // lazy propagation
    if (i > j) return;
    if ((L >= i) && (R <= j)) {                  // found the segment
      lazy[p] = val;                             // update this
      propagate(p, L, R);                        // lazy propagation
    }
    else {
      int m = (L+R)/2;
      update(l(p), L  , m, i          , min(m, j), val);
      update(r(p), m+1, R, max(i, m+1), j        , val);
      st[p] = conquer(st[l(p)],st[r(p)]);
    }
  }

public:
  SegmentTree(int sz) : n(sz), st(4*n), lazy(4*n, 0) {}

  SegmentTree(const vi &initialA) : SegmentTree((int)initialA.size()) {
    A = initialA;
    build(1, 0, n-1);
  }

  void update(int i, int j, int val) { update(1, 0, n-1, i, j, val); }

  int RMQ(int i, int j) { return RMQ(1, 0, n-1, i, j); }
};



int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int n,k;
  cin>>n>>k;
  vi arr(n);
  REP(i, n) {
    cin>>arr[i];
  }
  vi prev(n,-1);
  map<int,int>mp;
  vvi dp (k, vi(n,0));
  int cur =0;
  REP(i, n) {
    if (mp.find(arr[i])!= mp.end()) {
      cur += (i-mp[arr[i]]);
      prev[i] = mp[arr[i]];
      mp[arr[i]] = i;
    } else {
      prev[i] = -1;
      mp[arr[i]] = i;
    }
    dp[0][i] = cur;
  }
  REPL(i, 1, k) {
    SegmentTree seg(dp[i-1]);
    REP(j, n) {
      if (prev[j]!=-1) {
        seg.update(0, prev[j]-1, j-prev[j]);
      } 
      dp[i][j] = seg.RMQ(0, j);
    }
  }
  cout<<dp[k-1][n-1];

}