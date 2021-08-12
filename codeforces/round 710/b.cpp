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
	int n,k;
	cin>>n>>k;
	string str;
	cin>>str;
	int s,e;
	REP(i, n) {
		if (str[i] == '*') {
			s = i;
			break;
		}
	}
	REP(i, n) {
		if (str[n-1-i] == '*') {
			e = n-1-i;break;
		}
	}
	int co = s ==e? 1: 2;
	if (co != 1) {
		int cur = s;
		int xtra = 0;
		while (cur < e-k) {
			for (int i =k; i > 0; --i) {
				if (str[cur+i]=='*') {
					cur = cur+i;xtra++;break;
				}
			}
		}
		int cur2 = e;int xtra2 =0;
		while (cur2 > s+k) {
			for (int i =k; i > 0; --i) {
				if (str[cur2-i]=='*') {
					cur2 = cur2-i;xtra2++;break;
				}
			}
		}
		co += min(xtra,xtra2);
	}

	cout<<co<<"\n";
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