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
ll md = 1e9+7;
vll facts(100001);
map<int, set<int>> mp;
int mod(int a, int m) {                          // returns a (mod m)
  return ((a%m) + m) % m;                        // ensure positive answer
}
int extEuclid(int a, int b, int &x, int &y) {    // pass x and y by ref
  int xx = y = 0;
  int yy = x = 1;
  while (b) {                                    // repeats until b == 0
    int q = a/b;
    tie(a, b) = tuple(b, a%b);
    tie(x, xx) = tuple(xx, x-q*xx);
    tie(y, yy) = tuple(yy, y-q*yy);
  }
  return a;                                      // returns gcd(a, b)
}

int modInverse(int b, int m) {                   // returns b^(-1) (mod m)
  int x, y;
  int d = extEuclid(b, m, x, y);                 // to get b*x + m*y == d
  if (d != 1) return -1;                         // to indicate failure
  // b*x + m*y == 1, now apply (mod m) to get b*x == 1 (mod m)
  return mod(x, m);
}
ll C(int n, int k) {
	ll cn = facts[n];
	ll cnk = modInverse(facts[n-k], md);
	ll ck = modInverse(facts[k], md);
	return (((cn*cnk)%md)*ck)%md;
}
ll cal(int num, int lw, int hgh) {
	if (lw>hgh) {
		return 1;
	}
	auto it = mp[num].upper_bound(hgh);
	int indx = *prev(it);
	if (indx<lw) {
		return 0;
	}
	return (((cal(num, lw, indx-1) * cal(num+1, indx+1, hgh))%md) * C(hgh-lw, indx-lw))%md;
}
void solve(int tss) {
	int n;
	cin>>n;
	mp.clear();
	REP(i, n+1) {
		mp.insert({i,set<int>()});
		mp[i].insert(-999);
	}
	REP(i, n) {
		int x;
		cin>>x;
		mp[x].insert(i);
	}
	
	cout<<"Case #"<<tss<<": "<<cal(1,0,n-1)<<"\n";
}

int main()
{
	facts[0] = 1;	

	REPL(i, 1, 100001) {
		facts[i] = facts[i-1] * i;
		facts[i]%=md;
	}
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int tc;
	cin>>tc;
	REP(i, tc) {
		solve(i+1);
	}

}