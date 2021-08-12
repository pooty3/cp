#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define SORT(arr) sort(arr.begin(), arr.end())
#define LSOne(S) ((S)&-(S))
#define M_PI 3.1415926535897932384
#define INF 999999
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
	int n, m;
	cin>>n>>m;
	int tot =0;
	unordered_map<int,int> mp1,mp2;	
	set<int> s1;
	set<int> s2;	
	vi arr(n+1,0);
	REP(i, m) {
		int x,y;
		cin>>x>>y;
		if (x!=y) {
			mp1.insert({x,y});
			mp2.insert({y,x});
			arr[x]++;
			arr[y]++;
		}
	}
	REP(i, n+1) {
		if (arr[i]==1) {
			s1.insert(i);
		} else if (arr[i]==2) {
			s2.insert(i);
		} else {}
	}
	while (!s2.empty()||!s1.empty()) {
		while(!s1.empty()) {
			tot ++;
			int x = *s1.begin();
			auto it = mp1.find(x);
			int y;
			if (it!=mp1.end()){
				y= it->second;
				mp1.erase(x);
				mp2.erase(y);
			} else {
				y = mp2.find(x)->second;
				mp1.erase(y);
				mp2.erase(x);

			}
			if (s1.find(y)!=s1.end()) {
				s1.erase(y);
			} else {
				s2.erase(y);
				s1.insert(y);
			}
			s1.erase(x);
		}
		if (!s2.empty()) {
			tot +=2;
			int x = *s2.begin();
			int y = mp1.find(x)->second;
			mp1.erase(x);
			mp2.erase(y);
			s2.erase(x);
			s2.erase(y);
			s1.insert(x);
			s1.insert(y);
		}
	}
	cout<<tot<<"\n";

}

int main()
{
	int tc;
	cin>>tc;
	REP(i, tc) {
		solve();
	}

}