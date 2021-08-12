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
string exte(string &s, int k) {
	string ss = "";
	REP(i, k) {
		ss += s[i%s.size()];
	}
	return ss;
}
void solve() {
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	string ns;
	ns += s[0];
	REPL(i, 1, n) {
		if (s[i]<s[0]) {
			ns += s[i];
		} else {
			break;
		}
	}
	string ns2 = ns;
	int curind = ns.size();
	int co = 0;
	while (true) {
		string sss = ""; 
		bool smaller = false;
		while (true) {
			cout<<sss<<"\n";
			if (curind == n || s[curind] > s[0]) {
				ns2 += sss;
				goto done;
			}

			if (s[curind] < s[0] && co >= ns2.size()) {
				smaller = true;
				co++;
				curind++;
				sss += s[curind];
				continue;
			}
			if (co < ns2.size() && s[co] > s[curind]) {
				smaller = true;
				co++;
				curind++;
				sss += s[curind];
				continue;
			}
			if (s[curind] == s[0] && co >= ns2.size()) {
				ns2 += sss;
				co = 0;
				break;
			} 
			if (co < ns2.size() && s[co] == s[curind]) {
				co++;
				curind++;
				sss += s[curind];
				continue;
			}
			if (co < ns2.size() && s[co] < s[curind]) {
				if (smaller) {
					co++;
					curind++;
					sss += s[curind];
					continue;
				} else {
					goto done;
				}
			}

		}

	}
	done:
	cout<<exte(ns2, k);

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	REP(i, 1) {
		solve();
	}

}