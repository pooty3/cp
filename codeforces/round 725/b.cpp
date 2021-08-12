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
	int n;
	cin>>n;
	unordered_set<string> ss;
	REP(i, 26) {
		string s = "";
		s += (char)(i+'a');
		ss.insert(s);
	}
	REP(i, 26) {
		REP(j, 26) {
			string s = "";
			s += (char)(i+'a');
			s += (char)(j+'a');
			ss.insert(s);
			s = "a"+s;
			ss.insert(s);
		}
	}
	string s;
	cin>>s;
	REP(i, s.size()) {
		REPL(j, 1,4) {
			if (i+j<= (int)s.size()) {
				string sub = s.substr(i, j);
				if (ss.find(sub)!= ss.end()) {
					ss.erase(sub);
				}
			}
		}
	}
	string bst= "zzzzz";
	for (string sss: ss) {
		if (sss.size()<bst.size()||(sss.size()==bst.size() && sss<bst)) {
			bst = sss;
		}
	}
	cout<<bst<<"\n";

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