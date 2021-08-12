#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
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
	int n;
	cin>>n;
	vi rarr;
	vi barr;
	string r,b;
	cin>>r>>b;
	int re=0,bl=0;
	REP(i,n) {
		if (r[i]> b[i]) {
			re++;
		} 
		if (b[i]>r[i]) {
			bl++;
		}

	}
	cout<<(re==bl? "EQUAL":re>bl?"RED":"BLUE")<<"\n";


}

int main()
{
	int tc;
	cin>>tc;
	REP(i, tc) {
		solve();
	}

}