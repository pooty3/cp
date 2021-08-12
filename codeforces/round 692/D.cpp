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

int main()
{
	string str;
	cin>>str;
	ll x,y;
	cin>>x>>y;
	ll tot =0;
	ll count1=0;
	ll count0=0;
	REP(i, str.length()) {
		if (str[i]=='0') {
			tot += count1*y;
			count0++;
		} else if (str[i]=='1') {
			tot += count0*x;
			count1++;
		} else {
		}
	}
	ll tot1 =tot;
	ll acount1 = count1, bcount1 =0, acount0 =count0, bcount0=0;
	REP(i, str.length()) {
		if (str[i]=='0') {
			acount0 --;
			bcount0++;
		} else if (str[i]=='1') {
			acount1--;
			bcount1++;
		} else {
			ll c1 = bcount0*x + acount0*y;
			ll c0 = bcount1*y + acount1*x;
			if (c1< c0) {
				bcount1++;
				tot1 += c1;
			} else {
				bcount0++;
				tot1 +=c0;
			}
		}
	}
	ll tot2 = tot;
	acount1 = 0, bcount1 =count1, acount0 = 0, bcount0=count0;
	for (int i = str.length()-1; i>=0; i--){
		if (str[i]=='0') {
			acount0 ++;
			bcount0--;
		} else if (str[i]=='1') {
			acount1++;
			bcount1--;
		} else {
			ll c1 = bcount0*x + acount0*y;
			ll c0 = bcount1*y + acount1*x;
			if (c1< c0) {
				acount1++;
				tot2 += c1;
			} else {
				acount0++;
				tot2 +=c0;
			}
		}
	}
	cout<<min(tot1,tot2);

}