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

ll md =   998244353;
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
    for (; j; j -= LSOne(j)) {
 		sum += ft[j];
 		sum = (sum + md)%md;
    }
    return sum;
  }

  ll rsq(int i, int j) { return rsq(j) - rsq(i-1); } // inc/exclusion

  // updates value of the i-th element by v (v can be +ve/inc or -ve/dec)
  void update(int i, ll v) {
    for (; i < (int)ft.size(); i += LSOne(i)) {
      ft[i] += v;
      ft[i] = (ft[i]+md)%md;
    }
  }

  /*int select(ll k) {                             // O(log m)
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
  }*/
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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;cin>>n;
	vector<tuple<ll, ll, ll>> arr(n);

	REP(i, n) {
		int ed,st,up;
		cin>>ed>>st>>up;
		arr[i] = {ed, st, up};
	} 
	RUPQ ft(n);
	REP(i, n) {
		ft.range_update(i+1, i+1, 1);
	}
	ll curtot = get<0>(arr[n-1]) + 1;
	REP(i, n) {
		auto [ed, st, up] = arr[n-1-i];
		int looped = ft.point_query(n-i);
		if (up == 0) {
			looped--;
		} 
		curtot += (looped * (ed-st))%md;
		curtot %= md;
		tuple<ll,ll,ll> aa= {st,0LL,0LL};
		int idx = upper_bound(arr.begin(), arr.end(), aa) - arr.begin();
		if (idx+1 != n-i) {
			ft.range_update(idx+1, n-i-1, looped);
		}	
	}cout<<curtot;
}