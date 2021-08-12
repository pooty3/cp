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

void pr(int i, int y1,int y2) {
	cout<<i<<" "<<y1<<" "<<y2<<"\n";
}

void solve() {
	int n;
	cin>>n;
	vi arr(n);
	int x;
	REP(i, n) {
		cin>>x;
	}
	cout<<n*3<<"\n";
	REP(i, n/2) {
		int y1 = 2*i+1;
		int y2 = 2*i+2;
		pr(1,y1,y2);
		pr(2,y1,y2);
		pr(1, y1,y2);
		pr(1,y1,y2);
		pr(2,y1,y2);
		pr(1,y1,y2);
	}
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