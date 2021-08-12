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

int gcd(int a, int b) {
	if (a>b) {
		return gcd(b,a);
	}
	if (a==0) {
		return b;
	} else {
		return gcd(b%a, a);
	}
}

void solve() {
	string s1,s2;
	cin>>s1>>s2;
	int l1 = s1.length();
	int l2 = s2.length();
	int l = l1*l2/gcd(l1,l2);
	string ss1 = "", ss2 ="";
	REP(i, l/l1) {
		ss1 += s1;
	}
	REP(i,l/l2) {
		ss2 += s2;
	}
	if (ss1 == ss2) {
		cout<<ss1;
	} else {
		cout<<-1;
	} cout<<"\n";

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int tc;
	cin>>tc;
	REP(i, tc) {
		solve();
	}

}