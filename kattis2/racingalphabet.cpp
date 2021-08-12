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
int getind(char ch) {
	if (ch==' ') return 27;
	if(ch=='\'') return 28;
	return ch-'A'+1;
}

void solve() {
	string str;
	getline(cin,str);
	ld tot =0;
	int prev = getind(str[0]);
	REPL(i,1, str.size()) {

		int nxt = getind(str[i]);
		int diff = abs(nxt-prev);
		diff = min(diff, 28-diff);
		ld rad = M_PI / 28 * diff;
		tot += 2*2*rad;
		prev = nxt;

	}
	cout<<setprecision(10)<<tot+str.size()<<"\n";

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int tc;
	cin>>tc;
	string str;
	getline(cin, str);
	REP(i, tc) {
		solve();
	}

}