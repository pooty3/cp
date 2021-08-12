#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define SORT(arr) sort(arr.begin(), arr.end())
#define LSOne(S) ((S)&-(S))
#define M_PI 3.1415926535897932384
#define INF 999999
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
vi primes;
void solve() {
	int n;
	cin>>n;
	map<int, int> s;
	REP(i, n) {
		int x;
		cin>>x;
		for (int p : primes) {
			while (true) {
				if (x%(p*p)!=0){
					break;
				} else {
					x/=(p*p);
				}
			}
		}
		if (s.find(x)==s.end()) {
			s.insert({x, 0});
		}
		s[x]++;
	} 
	int nexttot=0;
	if (s.find(1)!=s.end()) {
		nexttot += s[1];
	}
	int tot =0;
	for (auto &[x, y]:s) {
		tot = max(y, tot);
		if (x!=1 && y%2==0) {
			nexttot += y;
		}
	}
	nexttot = max(nexttot, tot);
	int q;
	cin>>q;
	REP(i, q) {
		ll w;
		cin>>w;
		if (w==0) {
			cout<<tot<<"\n";
		} else {
			cout<<nexttot<<"\n";
		}
	}
	

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	primes.push_back(2);
	primes.push_back(3);
	REPL(i,4, 1001) {
		bool isPrime = true;
		REPL(j, 2,  ceil(sqrt(i))+1) {
			if (i%j==0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime) {
			primes.push_back(i);
		}
	} 
	int tc;

	cin>>tc;
	REP(i, tc) {
		solve();
	}

}