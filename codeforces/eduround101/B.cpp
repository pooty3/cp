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

void solve() {
	int n;
	cin>>n;
	vi a1(n+1);
	int cur=0;
	int x;
	a1[0]=0;
	REP(i, n) {
		cin>>x;
		cur+=x;
		a1[i+1] = cur;
	}
	int m;
	cin>>m;
	vi a2(m+1);
	cur=0;
	a2[0]=0;
	REP(i, m) {
		cin>>x;
		cur+=x;
		a2[i+1] = cur;
	}
	int curmax=0;
	REP(i,n+1) {
		REP(j,m+1) {
			curmax = max(curmax, a1[i]+a2[j]);
		}
	}
	cout<<curmax<<"\n";
	
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