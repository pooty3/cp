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

};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n,q;
	cin>>n>>q;
	FenwickTree ft(n);
	REP(i, n) {
		int k;
		cin>>k;
		ft.update(k, 1);
	}
	REP(i, q) {
		int x;cin>>x;
		if (x>0) {
			ft.update(x, 1);
		} else {
			int lw = 1;
			int hgh = n;
			while (lw<hgh) {
				int md = (lw+hgh)/2;
				if (ft.rsq(md)<abs(x)) {
					lw = md+1;
				} else {
					hgh = md;
				}
			}
			ft.update(lw, -1);
		}
	}
	REPL(i, 1, n+1) {
		if (ft.rsq(i)>0) {
			cout<<i;return 0;
		}
	}cout<<0<<"\n";

}