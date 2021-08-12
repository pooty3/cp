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

bool isPrime(ll N) {                             // good enough prime test
  if (N < _sieve_size) return bs[N];             // O(1) for small primes
  for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i)
    if (N%p[i] == 0)
      return false;
  return true;                                   // slow if N = large prime
} // note: only guaranteed to work for N <= (last prime in vll p)^2

// second part

set<int> primeFactors(ll N) {                         // pre-condition, N >= 1
  set<int> factors;
  for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i)
    while (N%p[i] == 0) {                        // found a prime for N
      N /= p[i];                                 // remove it from N
      factors.insert(p[i]);
    }
  if (N != 1) factors.insert(N);              // remaining N is a prime
  return factors;
}


int main()
{
	sieve(100005); 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n,q;cin>>n>>q;
	vector<set<int>> facts(100004);
	REPL(i,1, 100004) {
		facts[i] = primeFactors(i);
	}
	map<int,int> mp;
	vi arr(n);
	REP(i, n) {
		cin>>arr[i];
	}
	vi parr(n);
	REP(i, n) {
		set<int> &s = facts[arr[i]];
		int curmn = -1;
		for (auto v: s) {
			auto it2= mp.find(v);
			if (it2 != mp.end()) {
				curmn = max(curmn, it2->second);
			}
			mp[v] = i;
		}
		parr[i] = curmn;
	} 
	vi sarr(n);
	mp.clear();
	REP(i, n) {
		set<int> &s = facts[arr[n-1-i]];
		int curmx = n+1;
		for (auto v: s) {
			auto it2= mp.find(v);
			if (it2 != mp.end()) {
				curmx = min(curmx,it2->second);
			}
			mp[v] = n-1-i;
		}
		sarr[n-1-i] = curmx;
	} 
	vi parr2(n);
	int cur = 0;
	int bf = 0;
	REP(i, n) {
		if (parr[i] >=bf) {
			bf = i;
			cur++;
		}
		parr2[i] = cur;
	}
	vi sarr2(n);
	cur =0;
	bf =n-1;
	REP(i, n) {
		if (sarr[n-1-i] <= bf) {
			bf= n-1-i;
			cur++;
		}
		sarr2[n-1-i] = cur;
	}
	REP(i, q) {
		int l,r;cin>>l>>r;l--;r--;
		cout<<min(parr2[r] - parr2[l] + 1, sarr2[l] - sarr2[r] + 1)<<"\n";
	}
}