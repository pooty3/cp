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
struct word{
	ll occ;
	string st;
	string ed;
};
void solve() {
	int n;
	cin>>n;
	string lst;
	unordered_map<string, word> mp;
	REP(i, n) {
		string s1, s2;
		cin>>s1>>s2;
		lst = s1;
		if (s2 == ":=") {
			string s3;cin>>s3;
			word w = {0, s3, s3};
			if (s3.size()>=4) {
				if (s3.find("haha")!= string::npos) {
					w.occ++;
				}
				w.st = s3.substr(0,3);
				w.ed = s3.substr(s3.size()-3);
			}
			mp[s1] = w;
		} else {
			string s3,s4,s5;cin>>s3>>s4>>s5;
			word w3 = mp[s3];
			word w5 = mp[s5];
			ll o = w3.occ + w5.occ;
			string combimid = w3.ed + w5.st;
			REP(i, (int)combimid.size()-3) {
				if (combimid.substr(i, 4) == "haha") {
					o++;
				}
			}
			string s = w3.st + w5.st;
			if (s.size()>=4) {
				s = s.substr(0,3);
			}
			string e = w3.ed + w5.ed;
			if (e.size()>=4) {
				e = e.substr(e.size()-3);
			}
			word f = {o, s, e};
			mp[s1] = f;
		}
	}
	cout<<mp[lst].occ<<"\n";

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