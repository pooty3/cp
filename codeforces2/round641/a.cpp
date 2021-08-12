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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	set<int> primes;
	bool isPrime[200005];
	memset(isPrime, true, sizeof(isPrime));
	REPL(i, 2, 200001) {
		if (isPrime[i]) {
			primes.insert(i);
			for (int z = i*2; z < 200004; z+=i) {
				isPrime[z] = false;
			}
		}
	}
	int n;
	cin>>n;
	vi arr(n);
	REP(i, n) {
		cin>>arr[i];
	}
	ll ans = 1;
	set<int> primestotest;
	REP(i, 2) {
		for (int p: primes) {
			if (arr[i]%p==0) {
				primestotest.insert(p);
			}
		}
	}
	for (int p: primestotest) {
		int cursmall = INF;
		int cur2small = INF;
		REP(i,n) {
			int curmul = 0;
			int cur = arr[i];
			while (cur%p==0) {
				cur/=p;
				curmul++;
			}
			if (curmul<cursmall) {
				cur2small= cursmall;
				cursmall = curmul;
			} else if (curmul < cur2small) {
				cur2small = curmul;
			} else {

			}
		}
		REP(i, cur2small) {
			ans *=p;
		}
	}	cout<<ans;
}