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

void solve() {
	int aa,bb,k;
	cin>>aa>>bb>>k;
	vi b(aa+1,0), g(bb+1,0);
	vii p(k, {0,0});
	REP(i, k) {
		int bo;
		cin>>bo;
		b[bo]++;
		p[i].first = bo;
	}
	REP(i, k) {
		int gi;
		cin>>gi;
		g[gi]++;
		p[i].second = gi;
	}
	ll tot =0;
	REP(i,k) {
		tot += (1+k-b[p[i].first]- g[p[i].second]);
	}
		cout<<tot/2<<"\n";

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