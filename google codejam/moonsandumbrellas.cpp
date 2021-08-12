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

void solve(int zz) {
	int x,y;
	cin>>x>>y;
	string str;
	cin>>str;
	vi dpJ(str.length(), INF);
	vi dpC(str.length(), INF);
	REP(i, str.length()) {
		if (str[i] == 'J') {
			if (i==0) {
				dpJ[i] = 0;
			} else {
				dpJ[i] = min(dpC[i-1] + x, dpJ[i-1]);
			}
		} else if (str[i] == 'C') {
			if (i==0) {
				dpC[i] = 0;
			} else {
				dpC[i] = min(dpJ[i-1] + y, dpC[i-1]);
			}
		} else {
			if (i==0) {
				dpC[i] = 0;dpJ[i] = 0;
			} else {
				dpC[i] = min(dpJ[i-1] + y, dpC[i-1]);
				dpJ[i] = min(dpC[i-1] + x, dpJ[i-1]);
			}
		}
	}
	printf("Case #%d: %d\n",zz, min(dpC[str.length()-1], dpJ[str.length()-1]));
}

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	int tc;
	cin>>tc;
	REP(i, tc) {
		solve(i+1);
	}

}