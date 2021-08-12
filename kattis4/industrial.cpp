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
}
 set<int> poss;
 string cur;
 string str;
void recurse(int mask) {
	if (cur != "") {
		int val = stoi(cur);
		if (isPrime(val)) {
			poss.insert(val);
		}
	}

	REP(i, str.length()) {
		if (mask&(1<<i)) continue;
		cur += str[i];
		recurse(mask+(1<<i));
		cur.pop_back();
	}
}

 void solve() {
	poss.clear(); 	
 	cin>>str;
 	cur = "";
 	recurse(0);
 	cout<<poss.size()<<"\n";
 }
 
 int main()
 {
 	sieve(10000000);
 	ios_base::sync_with_stdio(false);
 	cin.tie(NULL); cout.tie(NULL);
 	int tc;
 	cin>>tc;
 	REP(i, tc) {
 		solve();
 	}
 
 }