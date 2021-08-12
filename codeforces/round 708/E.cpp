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
bitset<11000> bs;                             // 10^7 is the rough limit
set<int> primes;                                           // compact list of primes

void sieve(int upperbound) {                      // range = [0..upperbound]
  _sieve_size = upperbound+1;                    // to include upperbound
  bs.set();                                      // all 1s
  bs[0] = bs[1] = 0;                             // except index 0+1
  for (int i = 2; i < _sieve_size; ++i) if (bs[i]) {
    for (int j = i*i; j < _sieve_size; j += i) bs[j] = 0;
    primes.insert(i);                              // add prime i to the list
  }
}
map<int,int> mpprime;

void solve() {
	int n,k;
	cin>>n>>k;
	set<int> curs;
	int cc =0;
	REP(i, n) {
		int x;
		cin>>x;
		int cur = x;
		if (mpprime.find(x)== mpprime.end()) {
			for (int prime: primes) {
				if (prime * prime > cur) {
					break;
				} 
				while (cur%(prime*prime)==0) {
					cur /= (prime*prime);
				}
			}
			mpprime.insert({x, cur});
		}
		cur = mpprime[x];
		if (curs.find(cur) == curs.end()) {
			curs.insert(cur);
		} else {
			curs.clear();
			curs.insert(cur);
			cc++;
		}

	}
	cout<<(cc+1)<<endl;


}

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	sieve(10000);
	int tc;
	cin>>tc;
	REP(i, tc) {
		solve();
	}

}