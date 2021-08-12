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

string incre(string s1) {
	bool carry = false;
	for (int i = s1.length()-1; i>=0; i--) {
		if (s1[i] == '9') {
			s1[i] = '0';
			carry = true;
		} else {
			s1[i] = s1[i] + 1;
			carry = false;
			break;
		}
	} if (carry) {
		s1 = '0' + s1;
	}return s1;
}

void solve(int zz) {
	int n;cin>>n;
	vector<string> arr(n);
	REP(i, n) {
		cin>>arr[i];
	}
	int need =0;
	string cur = arr[0];
	REPL(i,1, n) {
		string nxt = arr[i];
		if (nxt.length() > cur.length()) {
			cur = nxt;
			continue;
		}
		if (nxt.compare(cur) == 0) {
			nxt += '0';
			cur = nxt;
			need++;
			continue;
		}
		string pf = cur.substr(0, nxt.length());
		string sf = cur.substr(nxt.length());
		int cmp = nxt.compare(pf);
		if (cmp < 0) {
			REP(i, sf.length()+1) {
				need++;
				nxt += '0';
			}
		} else if (cmp > 0) {
			REP(i, sf.length()) {
				need++;
				nxt += '0';
			}
		} else {
			string ss = incre(sf);
			need += ss.length();
			nxt += ss;
		}
		cur = nxt;
	}
	printf("Case #%d: %d\n", zz,need);
}

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	int tc;
	cin>>tc;
	REP(i, tc) {
		solve(i+1);
	}

}