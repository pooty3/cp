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
ll md;
vvll inversiontable(51, vll(50*50 + 1, 0));
void generateInversion() {
	inversiontable[1][0] = 1;
	REPL(i, 2, 51) {
		REP(j, i) {
			REP(k, 2501) {
				if (j + k > 50*50) continue;
				inversiontable[i][j + k] += inversiontable[i-1][k];
				inversiontable[i][j + k] %= md;
			}
		}
	}
}
vvll mindiff(51, vll(51,-1));
ll findmindiff(int i, int diff) {
	if (mindiff[i][diff]==-1) {
		ll totsum =0;
		ll cursum = 0;
		REPL(kk, diff, 50*50+1) {
			cursum += inversiontable[i-1][kk-diff];
			cursum %= md;
			totsum += (cursum * (inversiontable[i-1][kk]) %md);
			totsum %= md;
		}
		mindiff[i][diff]=totsum;
	}return mindiff[i][diff];
}
int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	int n;
	cin>>n>>md;
	generateInversion();
	vll ansDP(n+1,0);
	ansDP[1] = 0;
	REPL(i, 2, n+1) {
		ansDP[i] += (ansDP[i-1] * i)%md;
		ansDP[i] %= md;
		REP(j, i) {
			REPL(k, j+1, i) {
				int mindiff = (k-j)+1;
				ansDP[i] += findmindiff(i, mindiff);
				ansDP[i]%=md;
			}
		}
	}
	cout<<ansDP[n];

}