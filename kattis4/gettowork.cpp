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
int css =0;
void solve() {
	css++;
	int n,t;cin>>n>>t;t--;
	vi carr(n,0);
	vvi cars(n, vi());
	int e;cin>>e;
	REP(i,e) {
		int h,p;cin>>h>>p;h--;
		carr[h]++;
		cars[h].push_back(-p);
	}
	vi res(n,0);
	REP(i, n) {
		if (i == t) continue;
		int curamt = carr[i];
		SORT(cars[i]);
		for (auto p: cars[i]) {
			curamt += p;
			res[i]++;
			if (curamt <=0) break;
		}
		if (curamt >0) {
			printf("Case #%d: IMPOSSIBLE\n", css);return;
		}
	}
	printf("Case #%d: ", css);
	for (auto i: res) {
		cout<<i<<" ";
	}cout<<"\n";

}

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	int tc;
	cin>>tc;
	REP(i, tc) {
		solve();
	}

}