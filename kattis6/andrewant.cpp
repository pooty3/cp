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
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	int l,a;

	while (cin>>l>>a) {
		int curR=l+1;
		int curL=-1 ;
		int le =0;
		vi arr;
		REP(i, a) {
			int x;char c;
			cin>>x>>c;
			arr.push_back(x);
			if (c=='R') {
				curR = min(x, curR);
			} else {
				le++;
				curL = max(x, curL);
			}
		}
		SORT(arr);
		printf("The last ant will fall down in %d seconds ", max(l-curR, curL));
		if (l-curR == curL) {
			printf("- started at %d and %d.\n", arr[le-1], arr[le]);
		} else {
			printf("- started at %d.\n", l-curR >curL?arr[le]:arr[le-1]);
		}
	}
}
