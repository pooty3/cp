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

int mod(int a, int m) {                          // returns a (mod m)
  return ((a%m) + m) % m;                        // ensure positive answer
}

int modPow(int b, int p, int m) {                // assume 0 <= b < m
  if (p == 0) return 1;
  int ans = modPow(b, p/2, m);                   // this is O(log p)
  ans = mod(ans*ans, m);                         // double it first
  if (p&1) ans = mod(ans*b, m);                  // *b if p is odd
  return ans;                                    // ans always in [0..m-1]
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


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin>>n;
	set<int> no;
	ll cur=1;
	REPL(i, 1,n) {
		if (__gcd(i,n)==1) {
			no.insert(i);
			cur *= i;
			cur %= n;
		}
	}
	if (cur !=1 ) {
		no.erase(cur);
	}
	cout<<no.size()<<"\n";
	for (int i: no) {
		cout<<i<<" ";
	}

}