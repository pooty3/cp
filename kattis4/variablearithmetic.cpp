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
bool is_number(const string& s)
{
    return !s.empty() && find_if(s.begin(), 
        s.end(), [](unsigned char c) { return !isdigit(c); }) == s.end();
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	map<string, int> mp;
	while (true) {
		string state;
		getline(cin, state);
		if (state == "0") {
			break;
		}
		stringstream ss(state);
		string s1;
		vector<string> toks;
		ss>>s1;
		toks.push_back(s1);
		string s2;
		ss>>s2;
		if (s2 == "=") {
			string s3;
			ss>>s3;
			mp[s1] = stoi(s3);
		} else {
			string s3;
			while (ss>>s3) {
				if (s3 != "+") {
					toks.push_back(s3);
				}
			}
			int totval=0;
			vector<string> finals;
			for (auto tok: toks){
				if (is_number(tok)) {
					totval += stoi(tok);
				} else {
					if (mp.find(tok)!=mp.end()) {
						totval += mp[tok];
					} else {
						finals.push_back(tok);
					}
				}
			}
			bool missing = false;
			if (totval ==0) {
				missing = true;
			} else {
				cout<<totval;
			}
			for (auto tok: finals) {
				if (!missing) {
					cout<<" + ";
				} else {
					missing = false;
				}
				cout<<tok;
			}cout<<"\n";
		}
		
	}

}