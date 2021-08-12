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

void fillup(vi &farr, map<int,int> &mp) {
	for (auto [c,t]: mp) {
		REP(i, t) {
			farr.push_back(c);
		}
	}
}
void solve() {
	string s;
	cin>>s;
	map<int, int> mp;
	for (char c: s) {
		mp[c] ++;
	}
	int uniq = -1;
	for (auto [c, t]: mp) {
		if (t == 1) {
			uniq = c; break;
		}
	}
	vi farr;
	if (uniq!= -1) {
		farr.push_back(uniq);
		mp[uniq]--;
		fillup(farr, mp);
	} else {
		auto it = mp.begin();
		auto [c, t] = *it;
		if (mp.size() == 1) {
			cout<<s<<"\n"; return;
		} else if ((t-2)*2 <= s.length()-2) {
			farr.push_back(c);
			farr.push_back(c);
			REP(i, t-2) {
				int v = next(mp.begin())->first;
				farr.push_back(v);
				farr.push_back(c);
				mp[v]--;
				if (mp[v]==0) {
					mp.erase(v);
				}
			}
			mp[c]=0;
			fillup(farr, mp);
		} else if (mp.size() == 2) {
			farr.push_back(c);
			auto [c1, t1] = *next(it);
			REP(i, t1) {
				farr.push_back(c1);
			}
			REP(i, t-1) {
				farr.push_back(c);
			}
		} else {
			farr.push_back(c);
			int v2 = next(it)->first;
			farr.push_back(v2);
			mp[v2]--;
			REP(i, t-1) {
				farr.push_back(c);
			}
			int v3 = next(next(it))->first;
			farr.push_back(v3);
			mp[v3]--;
			mp[c] = 0;
			fillup(farr, mp);
		}
	}
	for (auto i: farr) {
		cout<<(char)(i);
	}cout<<"\n";
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