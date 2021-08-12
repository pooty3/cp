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
vll fib;
void getVal(int n, ll k) {
	if (n==1) {
		cout<<"N";
	} else if (n==2) {
		cout<<"A";
	} else {
		ll len = fib[n-2];
		if (k<len) {
			getVal(n-2, k);
		} else {
			getVal(n-1, k-len);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	ll k;
	cin>>n>>k;
	fib.assign(n+1, -1);
	fib[1] = 1;
	fib[2] = 1;
	REPL(i,3, n) {
		fib[i] = fib[i-2]+fib[i-1];
		fib[i] = min(k+1, fib[i]);
	}
	getVal(n,k-1);

}