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
int css = 0;
void solve() {
	css++;
	int n,a,b;
	cin>>n>>a>>b;
	vi arr(10000);
	REP(i, n) {
		cin>>arr[i];
	}
	int cur =n;
	while(true) {
		int curb1 = 1;
		int curb2 = 1;
		for (int i= cur-1; i>=0;--i) {
			if (curb1 < arr[i]) {
				goto fail;
			}
			curb1 -= arr[i];
			int temp = curb1;
			curb1 += curb2;
			curb2 = temp;
		}
		break;
		fail:
		cur++;
	}
	printf("Case #%d: %d\n", css, cur+1);

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