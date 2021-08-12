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
ll md =  998244353;
ll _sieve_size;
bitset<10000010> bs;                             // 10^7 is the rough limit
vll p;                                           // compact list of primes

void sieve(ll upperbound) {                      // range = [0..upperbound]
  _sieve_size = upperbound+1;                    // to include upperbound
  bs.set();                                      // all 1s
  bs[0] = bs[1] = 0;                             // except index 0+1
  for (ll i = 2; i < _sieve_size; ++i) if (bs[i]) {
    // cross out multiples of i starting from i*i
    for (ll j = i*i; j < _sieve_size; j += i) bs[j] = 0;
    p.push_back(i);                              // add prime i to the list
  }
}

bool isPrime(ll N) {                             // good enough prime test
  if (N < _sieve_size) return bs[N];             // O(1) for small primes
  for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i)
    if (N%p[i] == 0)
      return false;
  return true;                                   // slow if N = large prime
} // note: only guaranteed to work for N <= (last prime in vll p)^2

// second part

vll primeFactors(ll N) {                         // pre-condition, N >= 1
  vll factors;
  for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i)
    while (N%p[i] == 0) {                        // found a prime for N
      N /= p[i];                                 // remove it from N
      factors.push_back(p[i]);
    }
  if (N != 1) factors.push_back(N);              // remaining N is a prime
  return factors;
}

// third part

int numPF(ll N) {
  int ans = 0;
  for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i)
    while (N%p[i] == 0) { N /= p[i]; ++ans; }
  return ans + (N != 1);
}

int numDiffPF(ll N) {
  int ans = 0;
  for (int i = 0; i < p.size() && p[i]*p[i] <= N; ++i) {
    if (N%p[i] == 0) ++ans;                      // count this prime factor
    while (N%p[i] == 0) N /= p[i];               // only once
  }
  if (N != 1) ++ans;
  return ans;
}

ll sumPF(ll N) {
  ll ans = 0;
  for (int i = 0; i < p.size() && p[i]*p[i] <= N; ++i)
    while (N%p[i] == 0) { N /= p[i]; ans += p[i]; }
  if (N != 1) ans += N;
  return ans;
}

int numDiv(ll N) {
  int ans = 1;                                   // start from ans = 1
  for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i) {
    int power = 0;                               // count the power
    while (N%p[i] == 0) { N /= p[i]; ++power; }
    ans *= power+1;                              // follow the formula
  }
  return (N != 1) ? 2*ans : ans;                 // last factor = N^1
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	sieve(100001);
	int n;
	cin>>n;
	ll curtot = 1;
	ll pf = 1;
	REPL(i, 2, n+1) {
		curtot = pf + numDiv(i);
		curtot %= md;
		pf += curtot;
		pf %= md;
	}
	cout<<curtot;
}