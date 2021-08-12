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
	int n,l,r;
	cin>>n>>l>>r;
	map<int, int> left;
	map<int, int> right;
	REP(i, l) {
		int x;
		cin>>x;
		left[x]++;
	}
	int c = n/2;
	REP(i, r) {
		int x;
		cin>>x;
		if (left.find(x)!=left.end() && left[x]!=0) {
			left[x]--;
			c--;
		} else {
			right[x]++;
		} 
	}
	int needed = abs(l-r);
	if (l>r) {
		for (auto [col, amt]: left) {
			needed -= (amt/2)*2;
			if (needed <=0) break;
		}
	} else {
		for (auto [col, amt]: right) {
			needed -= (amt/2)*2;
			if (needed <=0) break;
		}
	}
	c += max(0, needed/2);
	cout<<c<<"\n";
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