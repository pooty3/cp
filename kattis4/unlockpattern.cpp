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
	vii arr(9);
	REP(i, 3) {
		REP(j, 3) {
			int x;cin>>x;x--;
			arr[x] = {i,j};
		}
	}
	ld dis=0;
	REPL(i,1, 9) {
		int dx = arr[i].first - arr[i-1].first;
		int dy = arr[i].second - arr[i-1].second;
		dis += sqrt(dx*dx+dy*dy);
	}
	cout<<setprecision(10)<<dis;
}