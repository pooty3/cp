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

ll _sieve_size;
bitset<10000010> bs;                             // 10^7 is the rough limit
vll p; 
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

map<ll,ll> primeFactors(ll N) {                         // pre-condition, N >= 1
  map<ll,ll> factors;
  for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i)
    while (N%p[i] == 0) {                        // found a prime for N
      N /= p[i];                                 // remove it from N
      factors[p[i]]++;
    }
  if (N > 1) factors[N]++;              // remaining N is a prime
  return factors;
}
ll vp(ll p, ll n) {                           // Legendre's formula
  int ans = 0;
  for (ll pi = p; pi <= n; pi *= p)
    ans += n/pi;                                 // floor by default
  return ans;
}
int main()
{
	sieve(10000000);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	ll n,m;
	while (cin>>n>>m) {
		bool able = true;
		if (m==0) {
			able = false;
		} else {
			for (auto [p, co]: primeFactors(m)) {
				if (vp(p, n)<co) {
					able= false;
					break;
				}
			}
		}
		cout<<m<<(able?" divides ":" does not divide ")<<n<<"!\n";
	}
}