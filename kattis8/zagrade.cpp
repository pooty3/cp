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
string torem(string &s, set<int> &arr) {
	string cur = "";
	REP(i, s.length()) {
		if (arr.find(i)==arr.end()) {
			cur += s[i];
		}
	}return cur;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string s;
	set<string> ss;
	cin>>s;
	stack<int> st;
	vii parr;
	REP(i, s.length()) {
		if (s[i]=='(') {
			st.push(i);
		}
		if (s[i]==')') {
			int v = st.top();st.pop();
			parr.push_back({v,i});
		}
	}
	REPL(i,1, (1<<parr.size())) {
		set<int> cur;
		REP(j, parr.size()) {
			if (i&(1<<j)) {
				cur.insert(parr[j].first);
				cur.insert(parr[j].second);
			}
		}
		ss.insert(torem(s, cur));
	}
	for (auto sss:ss) {
		cout<<sss<<"\n";
	}
}