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
 ii ppp = {0,0};
class SegmentTree {                              // OOP style
private:
  int n;                                         // n = (int)A.size()
  vii st, lazy;                                // the arrays
 
  int l(int p) { return  p<<1; }                 // go to left child
  int r(int p) { return (p<<1)+1; }              // go to right child
 
  ii conquer(ii a, ii b) {
    if (a == ppp) return b;                       // corner case
    if (b == ppp) return a;
    return max(a, b);                            // RMQ
  }
 
  void propagate(int p, int L, int R) {
    if (lazy[p] != ppp) {                         // has a lazy flag
      st[p] = conquer(st[p], lazy[p]);                           // [L..R] has same value
      if (L != R) {
 
      	lazy[l(p)] = conquer(lazy[l(p)], lazy[p]);
      	lazy[r(p)] = conquer(lazy[r(p)], lazy[p]);
      }                                // not a leaf    // propagate downwards                         // time to update this
      lazy[p] = ppp;                             // erase lazy flag
    }
  }
 
  ii RMQ(int p, int L, int R, int i, int j) {   // O(log n)
    propagate(p, L, R);                          // lazy propagation
    if (i > j) return ppp;                        // infeasible
    if ((L >= i) && (R <= j)) return st[p];      // found the segment
    int m = (L+R)/2;
    return conquer(RMQ(l(p), L  , m, i          , min(m, j)),
                   RMQ(r(p), m+1, R, max(i, m+1), j        ));
  }
 
  void update(int p, int L, int R, int i, int j, ii val) { // O(log n)
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
      st[p] = conquer(st[l(p)], st[r(p)]);
      /*int lsubtree = (lazy[l(p)] != -1) ? lazy[l(p)] : st[l(p)];
      int rsubtree = (lazy[r(p)] != -1) ? lazy[r(p)] : st[r(p)];
      st[p] = (lsubtree <= rsubtree) ? st[l(p)] : st[r(p)];*/
    }
  }
 
public:
  SegmentTree(int sz) : n(sz), st(4*n, ppp), lazy(4*n, ppp) {}
 
 
  void update(int i, int j, ii val) { update(1, 0, n-1, i, j, val); }
 
  ii RMQ(int i, int j) { return RMQ(1LL, 0, n-1, i, j); }
};

int main()
{
	/*SegmentTree seg1(10000);
	seg1.update(1,5, {5,4});
	seg1.update(2,6, {7,6});
	seg1.update(3,7, {4,1});
	REP(i, 10) {
		cout<<seg1.RMQ(i,i).first<<" ";
	}*/
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n,m;
	//n = 1000;
	//m = 1000;
	cin>>n>>m;

	vector<vii> arr(n,vii());
	set<int> ss;
	REP(i, m) {
		int idx,l,r;
		/*idx = rand()%n;
		l = rand()%upp;
		ll diff = rand()%(upp/100000);
		if (l+diff > upp) {
			l = l-upp;
		}	
		r = l + upp;
		r = rand()%upp;*/
		cin>>idx>>l>>r;
		idx--;l--;r--;
		arr[idx].push_back({l,r});
		ss.insert(l);
		ss.insert(r);
	}
	map<int, int> cmp;
	int curv =0;
	for (auto j : ss) {
		cmp[j] = curv;curv++;
	}
	vector<vii> temp(n, vii());
	REP(i, n) {
		for (auto [ll,rr]: arr[i]) {
			temp[i].push_back({cmp[ll], cmp[rr]});
		}
	}
	swap(temp, arr);
	SegmentTree seg(curv);
	vii curbest(n);
	REP(i, n) {
		ii curbst = {0,0};
		for (auto [l,r]: arr[i]) {
			curbst = max(curbst, seg.RMQ(l,r));
		}
		curbest[i] = curbst;
		curbest[i].first++;
		if (curbest[i].first == 1) {
			curbest[i].second = -1;
		}
		for (auto [l,r]: arr[i]) {
			seg.update(l,r, {curbst.first+1, i});
		}
	}
	int curidx = 0;
	REP(i, n) {
		if (curbest[i] > curbest[curidx]) {
			curidx = i;
		}
	}
	int k = n-curbest[curidx].first;
	cout<<k<<"\n";
	set<int> wanted;
	while (true) {
		wanted.insert(curidx);
		if (curbest[curidx].first == 1) {
			break;
		}
		curidx = curbest[curidx].second;
	}
	assert(wanted.size() == n-k);
	REP(i, n) {
		if (wanted.find(i)== wanted.end()) {
			cout<<(i+1)<<" ";
		}
	}
}