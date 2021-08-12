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
bitset<100010> bs;                             // 10^7 is the rough limit
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

// second part

set<int> primeFactors(ll N) {                         // pre-condition, N >= 1
  set<int> factors;
  for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i)
    while (N%p[i] == 0) {                        // found a prime for N
      N /= p[i];                                 // remove it from N
      factors.insert(p[i]);
    }
  if (N != 1) factors.push_back(N);              // remaining N is a prime
  return factors;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string s;
	cin>>s;
	vi arr(26,0);
	for (char c: s) {
		arr[c-'a']++;
	}
	int cg = 0;
	for (int i: arr) {
		cg = __gcd(cg, i);
	}
	REPL(i,1, cg+1) {
		if (cg%i!=0) continue;
		vi carr(26);
		REP(j, 26) {
			carr[j] = arr[j]/i;
		}
		bool able = true;
		REP(pp, )
	}
}