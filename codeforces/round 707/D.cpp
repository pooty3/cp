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
ll extEuclid(ll a, ll b, ll &x, ll &y) {    // pass x and y by ref
  ll xx = y = 0;
  ll yy = x = 1;
  while (b) {                                    // repeats until b == 0
    ll q = a/b;
   	ll t = b; b = a%b; a = t;
   	t = xx; xx = x- q*xx; x = t;
   	t = yy; yy = y - q*yy; y = t;
  }
  return a;                                      // returns gcd(a, b)
}

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	int n,m,k;
	cin>>n>>m>>k;
	map<ll, ll> mp;
	ll gd = __gcd(n,m);
	ll lm = n*m /gd;
	set<int> samearr;
	ll xx,yy;
	ll zz = extEuclid(n, m, xx, yy);
	yy *= -1;
	REP(i, n) {
		ll x;
		cin>>x;
		mp.insert({x,i});
	}
	REP(i, m) {
		ll y;
		cin>>y;
		if (mp.find(y)==mp.end())continue;
		ll dy = mp[y];
		ll diff = i - dy;
		if (diff%gd != 0) continue;
		ll txx = xx * (diff/gd);
		ll tyy = yy * (diff/gd);
		ll v = txx * n + dy;
		assert(v == tyy*m + i);
		samearr.insert(v);
	}
	map<ll, ll> mrr;
	int i =1;
	if (samearr.size()==0) {
		cout<<k; return 0;
	}
	FOREACH(it, samearr) {
		mrr.insert({*it,i});
		cout<<(*it)<<" ";
		i++;
	}
	ll angerpercycle = lm - samearr.size();
	ll cycles = (k-1)/angerpercycle;
	ll diff = (k-1)%angerpercycle + 1;
	ll hgh = lm-1;
	ll lw = 0;
	while (hgh > lw) {
		int md = (hgh + lw)/2;
		auto it = mrr.upper_bound(md);
		ll happy;
		if (it ==mrr.begin()) {
			happy = 0;
		} else {
			happy = prev(it)->second;
		}
		ll ind = md+1-happy;
		if (ind < diff) {
			lw = md+1;
		} else {
			hgh = md;
		}
	}
	cout<<lw;
	cout<<(cycles * lm) + lw + 1;


}