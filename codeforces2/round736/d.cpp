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
	int n;cin>>n;
	vii arr(n);
	REP(i, n) {
		int x,y;
		cin>>x>>y;
		x/=2;
		y/=2;
		arr[i] = {x,y};
	}
	ll tot =0;
	REP(i, n) {
		vvi parr(2, vi(2,0));
		REP(j, n) {
			if (i==j) continue;
			int dx = abs(arr[j].first-arr[i].first);
			int dy = abs(arr[j].second-arr[i].second);
			parr[dx%2][dy%2]++;
		}
		tot += (n-1)*(n-2)/2;
		tot -= parr[0][1]*parr[1][0];
		tot -= parr[1][1] * (parr[1][0] + parr[0][1]);
	}
	cout<<tot/3;
}