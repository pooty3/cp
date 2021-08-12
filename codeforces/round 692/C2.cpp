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
	int n, m;
	cin>>n>>m;
	int tot =0;
	vii s;
	vi arr(n+1,0);
	REP(i, m) {
		int x,y;
		cin>>x>>y;
		if (x!=y) {
			s.push_back({x,y});
			arr[x]++;
			arr[y]++;
		}
	}
	FOREACH(it, s) {
		int x= it->first;
		int y = it->second;
		if (arr[x]>1&&arr[y]>1) {
			tot +=2;
			arr[x]--;
			arr[y]--;
		} else {
			tot++;
			arr[x]--;
			arr[y]--;
		}
	}
	cout<<tot<<"\n";
 
}
 
int main()
{
	int tc;
	cin>>tc;
	REP(i, tc) {
		solve();
	}
 
}