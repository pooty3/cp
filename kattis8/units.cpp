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
struct frac {
	ll num;
	ll dem;
};
frac mul(frac a,frac b) {
	ll nn = a.num*b.num;
	ll nd = a.dem*b.dem;
	return {nn/__gcd(nn,nd), nd/__gcd(nn,nd)};
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true) {
		int n;cin>>n;
		if (n==0) break;
		map<string, map<string, frac>> adj;
		string str;
		REP(i, n) {
			cin>>str;
			adj.insert({str, map<string, frac>()});
		}
		REP(i, n-1) {
			string s1,s2,s4;
			ll s3;
			cin>>s1>>s2>>s3>>s4;
			adj[s1].insert({s4,{s3,1}});
			adj[s4].insert({s1, {1,s3}});
		}
		map<string, frac> vals;
		vals[str] = {1,1};
		stack<string> st;
		st.push(str);
		while (!st.empty()) {
			auto u = st.top();
			st.pop();
			for (auto &[v, w]: adj[u]) {
				if (vals.find(v)!=vals.end()) continue;
				vals[v] = mul(vals[u], w);
				st.push(v);
			}
		}
		ll lm = 1;
		for (auto [s, val]: vals) {
			lm = (val.dem * lm)/__gcd(lm, val.dem);
		}
		set<pair<int, string>> ans;
		for (auto [s, val]: vals) {
			ans.insert({val.num*lm/val.de,s});
		}
		FOREACH(it, ans) {
			cout<<(it->first)<<(it->second);
			if (next(it)!= ans.end()) {
				cout<<" = ";
			} else {
				cout<<"\n";
			}
		}
	}

}