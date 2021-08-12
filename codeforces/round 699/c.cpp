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
	int n,m;
	cin>>n>>m;
	vi aarr(n), barr(n), carr(m);
	map<int, int> wcol;
	map<int, set<int>> needed;
	REP(i, n) {
		cin>>aarr[i];
	}
	REP(i, n) {
		cin>>barr[i];
		if (barr[i]!=aarr[i]) {
			if (needed.find(barr[i])== needed.end()) {
				needed.insert({barr[i], set<int>()});
			}		
			needed[barr[i]].insert(i);
		}
		if (wcol.find(barr[i])== wcol.end()) {
			wcol.insert({barr[i], i});
		}
	}
	REP(i, m) {
		cin>>carr[i];
	}
	bool fail = false;
	vi arr;
	int last;
	if (wcol.find(carr[m-1])== wcol.end()) {
		fail = true;
	} else {
		auto it = needed.find(carr[m-1]);
		if (it!=needed.end()) {
			last = *(it->second).begin();
			(it->second).erase(last);
		} else {
			last = wcol[carr[m-1]];
		}
		arr.push_back(last);
		for (int i = m-2; i>=0; --i) {
			it = needed.find(carr[i]);
			if (it != needed.end() && !(it->second).empty()) {
				int v = *(it->second).begin();
				arr.push_back(v);
				(it->second).erase(v);
			} else {
				arr.push_back(last);
			}
		}
		FOREACH(it2, needed) {
			if (!(it2->second).empty()) {
				fail = true;
				break;
			}
		}
	}
	if (fail) {
		cout<<"NO\n";
	}else {
		cout<<"YES\n";
		REP(i, m) {
			cout<<(arr[m-1-i]+1)<<" ";
		}
		cout<<"\n";
	}


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