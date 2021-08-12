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
	int n;cin>>n;
	vll aarr(n), barr(n);
	REP(i, n) {
		cin>>aarr[i];
	}
	REP(i, n) {
		cin>>barr[i];
	}
	vvll rarr(n, vll(n,0));
	REP(i, n) {
		ll cur =0;
		REP(j, i) {
			if (j+i==n)break;
			cur += aarr[i-j-1]*barr[i+j];
			cur += barr[i-j-1]*aarr[i+j];
			rarr[i-j-1][i+j] = cur;
		}
	} 
	REP(i, n) {
		ll cur = rarr[i][i] = aarr[i] * barr[i];
		REP(j, i) {
			if (j+1+i==n) break;
			cur += aarr[i-j-1]*barr[i+j+1];
			cur += barr[i-j-1]*aarr[i+j+1];
			rarr[i-j-1][i+j+1] = cur;
		}
	}
	vll parr(n+1);
	vll sarr(n+1);
	parr[0] = sarr[n] =0;
	REPL(i,1, n+1) {
		parr[i] = parr[i-1] + aarr[i-1]*barr[i-1];
		sarr[n-i] = sarr[n-i+1] + aarr[n-i]*barr[n-i];
	}
	ll mx =0;

	REP(i, n) {
		REPL(j, i, n) {
			ll val = rarr[i][j] + parr[i] + sarr[j+1];
			mx = max(mx,val);
		}
	} cout<<mx;

}