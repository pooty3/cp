#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define SORT(arr) sort(arr.begin(), arr.end())
#define LSOne(S) ((S)&-(S))
#define M_PI 3.1415926535897932384
#define INF 1999999999
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
	map<int, map<int, vi>> mp;
	REP(i, n) {
		int v,w;
		cin>>v>>w;
		int u,h;
		if (v>w) {
			u = v;
			h = w;
		} else {
			u = w;
			h = v;
		}
		if (mp.find(u)==mp.end()) {
			mp.insert({u, map<int, vi>()});
		}
		if (mp[u].find(h)==mp[u].end()) {
			mp[u].insert({h, vi()});
		}
		mp[u][h].push_back(i);
	}
	vi vals(n, 0);
	int curmn = INF;
	int curind = -2;
	FOREACH(it, mp) {
		map<int,vi> &mp2 = it->second;
		for (auto &[v, ar2] : mp2) {
			FOREACH(it, ar2) {
				if (v > curmn) {
				vals[*it] = curind;
			} else {
				vals[*it] = -2;
			}
			}

		}
		int newmn = mp2.begin()->first;
		if (curmn >newmn) {
			curmn = newmn;
			curind = (mp2.begin()->second)[0];
		}
	}
	REP(i, n) {
		cout<<(vals[i]+1)<<" ";
	}
	cout<<"\n";

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