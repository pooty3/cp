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
	string s,t;
	cin>>s>>t;
	int ss  =s.size();
	int tt = t.size();
	REP(i, ss) {
		if (s[i] != t[0]) continue;
		REP(j, ss) {
			if (i+j >= ss) continue;
			int rm = tt-1-j;
			if (i+j-rm <0) continue;
			int curindT = 0;
			int curindS = i;
			REP(z, j) {
				curindS++;
				curindT++;
				if (t[curindT]!= s[curindS]) {
					goto out;
				}
			}
			REP(z, rm) {
				curindT++;
				curindS--;
				if (t[curindT]!= s[curindS]) {
					goto out;
				}
			}
			cout<<"YES\n"; return;
			out:
			int xxx=1;
		}
	}cout<<"NO\n"; 
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