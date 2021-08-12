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
vll bs(21000000, 1); 
                        // 10^7 is the rough limit
vll primes;                                           // compact list of primes
void sieve(ll upperbound) {    
                  // range = [0..upperbound]
  _sieve_size = upperbound+1;                    // to include upperbound                                     // all 1s                         // except index 0+1
  for (ll i = 2; i < _sieve_size; ++i) if (bs[i] == 1) {
    for (ll j = i; j < _sieve_size; j += i) bs[j] *= 2;
    primes.push_back(i);                              // add prime i to the list
  }
}
/*
unordered_map<ll, ll> memo;
ll findval(ll N) { 
	if (memo.find(N)!=memo.end()) {
		return memo[N]; 
	}                    // pre-condition, N >= 1
  ll c =1;
  for (int i = 0; i < (int)primes.size() && primes[i]*primes[i] <= N; ++i) {
    int cc =1;
    while (N%primes[i] == 0) {                        // found a prime for N
      N /= primes[i];                                 // remove it from N
      cc++;
    }
    if (cc >1) {
    	c<<=1;
    }
   // c *= (cc!= 1 ? 2 : 1);
	}
  if (N != 1) {
  	c*=2;
  }              // remaining N is a prime
  return c;
}

ll findval(ll N) {
	if (memo.find(N)==memo.end()) {
		memo[N] = primeFactors(N);
	}
	return memo[N];
}*/
void solve() {
	int x,c,d;
	cin>>c>>d>>x;
	ll totcount =0;
	REPL(i, 1, sqrt(x)+2) {
		if (i*i > x) break;
		if (x%i != 0) continue;
		int v1 = i;
		int v2 = x/i;
		if ((v1+d)%c == 0) {
			int compi = (v1+d)/c;
			totcount += bs[compi];
		} 
		if (v2!=v1) {
			if ((v2+d)%c==0) {
				int compi = (v2+d)/c;
				totcount += bs[compi];
			}
		}
	}
	cout<<totcount<<"\n";

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	sieve(20100000);
	int tc;
	cin>>tc;
	REP(i, tc) {
		solve();
	}

}