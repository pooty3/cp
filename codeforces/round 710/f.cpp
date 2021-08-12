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
	int n;
	cin>>n;
	int co =0;
	vi rarr(n);
	vi carr(n);
	REP(i, n) {
		cin>>rarr[i];
	}
	REP(i, n) {
		cin>>carr[i];
	}
	vii pts(n);
	pts.push_back({1,1});
	REP(i, n) {
		pts[i] = {rarr[i], carr[i]};
	}
	SORT(pts);
	REPL(i, 1, n+1) {
		auto [r1,c1] = pts[i-1];
		auto [r2,c2] = pts[i];
		int dr = r2- r1;
		int dc = c2 - c1;
		int right = dc;
		int left = dr - dc;
		bool iseven = (r1 + c1)%2 ==0;
		if (left == 0) {
			co +=  iseven ? right:0;continue;
		} 
		if (iseven) {
			co += left/2;
		} else {
			co += (left+1)/2;
		}
	}
	cout<<co<<"\n";
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