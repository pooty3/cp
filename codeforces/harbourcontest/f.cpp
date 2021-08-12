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
/*
class node{
	int l,r;
	ll val;
	ll prop;
	node* lnode = nullptr;
	node* rnode = nullptr;
	public: 
		node(int left, int right) {
			l= left;
			r = right;
			prop = 0;
			val =0;
			if (left!= right) {
				int mid = (left+right)/2;
				lnode = new node(left, mid);
				rnode = new node(mid+1, right);
			}
		}
		void propagate() {
			if(prop!=0) {
				val+= prop*(r-l+1);
				if (l!=r) {
					lnode->prop += prop;
					rnode->prop += prop;
				}
				prop = 0;
			}
		}
		ll rquery(int leftq, int rightq) {
			propagate();
			if (rightq < l || leftq > r) return 0;
			if (l>=leftq && r <=rightq) {
				return val;
			}
			return lnode->rquery(leftq, rightq) + rnode->rquery(leftq, rightq);
		}
		void rupdate(int leftq, int rightq, ll addval) {
			propagate();
			if (rightq < l || leftq > r) return;
			if (l>=leftq && r <=rightq) {
				prop += addval;
				propagate();
			} else {
				lnode->rupdate(leftq, rightq, addval);
				rnode->rupdate(leftq, rightq, addval);
				val = lnode->val+ rnode->val;
			}
		}
};	*/
class FenwickTree {                              // index 0 is not used
private:
  vll ft;                                        // internal FT is an array
public:
  FenwickTree(int m) { ft.assign(m+1, 0); }      // create an empty FT

  void build(const vll &f) {
    int m = (int)f.size()-1;                     // note f[0] is always 0
    ft.assign(m+1, 0);
    for (int i = 1; i <= m; ++i) {               // O(m)
      ft[i] += f[i];                             // add this value
      if (i+LSOne(i) <= m)                       // i has parent
        ft[i+LSOne(i)] += ft[i];                 // add to that parent
    }
  }

  FenwickTree(const vll &f) { build(f); }        // create FT based on f

  FenwickTree(int m, const vi &s) {              // create FT based on s
    vll f(m+1, 0);
    for (int i = 0; i < (int)s.size(); ++i)      // do the conversion first
      ++f[s[i]];                                 // in O(n)
    build(f);                                    // in O(m)
  }

  ll rsq(int j) {                                // returns RSQ(1, j)
    ll sum = 0;
    for (; j; j -= LSOne(j))
      sum += ft[j];
    return sum;
  }

  ll rsq(int i, int j) { return rsq(j) - rsq(i-1); } // inc/exclusion

  // updates value of the i-th element by v (v can be +ve/inc or -ve/dec)
  void update(int i, ll v) {
    for (; i < (int)ft.size(); i += LSOne(i))
      ft[i] += v;
  }

  int select(ll k) {                             // O(log m)
    int p = 1;
    while (p*2 < (int)ft.size()) p *= 2;
    int i = 0;
    while (p) {
      if (k > ft[i+p]) {
        k -= ft[i+p];
        i += p;
      }
      p /= 2;
    }
    return i+1;
  }
};

class RUPQ {                                     // RUPQ variant
private:
  FenwickTree ft;                                // internally use PURQ FT
public:
  RUPQ(int m) : ft(FenwickTree(m)) {}
  void range_update(int ui, int uj, ll v) {
    ft.update(ui, v);                            // [ui, ui+1, .., m] +v
    ft.update(uj+1, -v);                         // [uj+1, uj+2, .., m] -v
  }                                              // [ui, ui+1, .., uj] +v
  ll point_query(int i) { return ft.rsq(i); }    // rsq(i) is sufficient
};

class RURQ  {                                    // RURQ variant
private:                                         // needs two helper FTs
  RUPQ rupq;                                     // one RUPQ and
  FenwickTree purq;                              // one PURQ
public:
  RURQ(int m) : rupq(RUPQ(m)), purq(FenwickTree(m)) {} // initialization
  void range_update(int ui, int uj, ll v) {
    rupq.range_update(ui, uj, v);                // [ui, ui+1, .., uj] +v
    purq.update(ui, v*(ui-1));                   // -(ui-1)*v before ui
    purq.update(uj+1, -v*uj);                    // +(uj-ui+1)*v after uj
  }
  ll rsq(int j) {
    return rupq.point_query(j)*j -               // optimistic calculation
           purq.rsq(j);                          // cancelation factor
  }
  ll rsq(int i, int j) { return rsq(j) - rsq(i-1); } // standard
};

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	/*RURQ aa(10);
	aa.range_update(5,8,7);
	REPL(i,1, 11) {
		cout<<aa.rsq(i,i)<<" ";
	}*/
	int n;cin>>n;
	ll mx = 300000;
	vll arr(n);
	REP(i, n) {
		cin>>arr[i];
	}
	RURQ atree(mx);
	RURQ btree(mx);
	//node* btree = new node(0, max);
	//node* atree = new node(0, max);
	ll cursum = 0;
	ll curtot = 0;
	REP(i, n) {
		curtot += arr[i]*(i);
		curtot += cursum;
		cursum += arr[i];
		//cout<<curtot<<" ";
		curtot -= atree.rsq(arr[i], arr[i]);
		//curtot -= atree->rquery(arr[i], arr[i]);
		//cout<<curtot<<" ";
		int cur = 1;
		while (cur * arr[i] <= mx) {
			atree.range_update(cur*arr[i], min(mx,(cur+1)*arr[i]-1), cur*arr[i]); cur++;
			//atree->rupdate(cur*arr[i], (cur+1)*arr[i]-1, cur*arr[i]);cur++;
		}
		//cout<<curtot<<" ";
		cur = 1;
		while (cur*arr[i]<=mx) {
			//curtot -= btree->rquery(cur*arr[i], (cur+1)*arr[i]-1) * arr[i] * cur;cur++;
			curtot -= btree.rsq(cur*arr[i], min(mx,(cur+1)*arr[i]-1))*arr[i]*cur;cur++;
		}
		//cout<<curtot<<" ";
		//btree->rupdate(arr[i], arr[i], 1);
		btree.range_update(arr[i], arr[i], 1);
		cout<<curtot<<" ";
	}
}