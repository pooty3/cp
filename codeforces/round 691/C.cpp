#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
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

ll gcd (ll a, ll b) {
	if (a==0) {
		return b;
	} else if (b==0) {
		
		return a;
	} else {
		if (a<b) {
			return gcd(a, b%a);
		} else {

			return gcd(a%b,b);
		}
	}
} 
int main()
{

ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	set<ll> aarr;
	vll	barr(m);
	REP(i, n) {
		ll x;
		cin>>x;	
		aarr.insert(x);
	}
	REP(i, m) {
		cin>>barr[i];
	}
	if (aarr.size()==1) {
		ll val = *aarr.begin();
		REP(i, m) {
			cout<<(val + barr[i])<<" ";
		}
	} else {
		set<ll> darr;
		FOREACH(it, aarr) {
			if (next(it)!=aarr.end()) {
				darr.insert(abs((*it)- (*next(it))));
			}
		}
		ll div = *(darr.begin());
		FOREACH(it, darr) {
			div = gcd(div, *it);
		}
		ll r = *aarr.begin() % div;
		REP(i, m) {
			ll val = gcd(r+ barr[i], div);
			cout<<val<<" ";
		}

	}

}