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
	ll cur = 1;
	int twos = 0;
	int n;cin>>n;
	bool bigger = false;
	REPL(i,1, n+1) {
		ll t =i;
		while (t%2==0) {
			t/=2;
			twos++;
		}
		while (t%5==0) {
			t/=5;
			twos--;
		}
		cur *= t;
		if (cur>=1000) {
			bigger = true;
		}
		cur%=1000;
	}
	REP(i,twos) {
		cur *=2;
		if (cur>1000) {
			bigger = true;
		}
		cur %=1000;
	}
	if (bigger) {
		printf("%03d", cur);
	} else {
		printf("%d", cur);
	}
}