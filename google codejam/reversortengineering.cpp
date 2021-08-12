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

vi rev(int st, int len, int c) {
	if (len == 1) {
		vi arr = {st};
		return arr;
	}
	if (c >= len-1) {
		vi res = rev(st+1, len-1, c-len+1);
		reverse(res.begin(), res.end());
		res.push_back(st);
		return res;
	} else {
		vi arr(len);
		REP(i, len) {
			if (i==c) {
				arr[i] = st;
			} else if (i < c) {
				arr[i] = st + (c-i);
			} else {
				arr[i] = i + st;
			}
		}
		return arr;
	}
}

void solve(int zzz) {
	int n,c;
	cin>>n>>c;
	c-= (n-1);
	if (c <0 || c>n*(n-1)/2) {
		printf("Case #%d: IMPOSSIBLE\n",zzz);return;
	} else {
		vi arr = rev(1, n, c);
		printf("Case #%d: ",zzz);
		for (int i : arr) {
			cout<<i<<" ";
		}
		cout<<"\n";
	}

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