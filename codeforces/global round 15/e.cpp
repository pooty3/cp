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
typedef tuple<int, ll, ll> edge;
typedef double ld;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, k;cin>>n>>k;
	map<int, vi> mp;
	REP(i, n*k) {
		int u;cin>>u;
		u--;
		if(mp.find(u)==mp.end()) {
			mp.insert({u, vi()});
		}
		mp[u].push_back(i);
	} 
	set<int> taken;
	vii ans(n);
	int mx = n/(k-1);
	if (n%(k-1)!=0) {
		mx++;
	}
	REP(i, k-1) {
		int remain = min(mx, n-(int)taken.size());
		vii arr;
		REP(j, n) {
			if (taken.find(j)==taken.end()) {
				arr.push_back({mp[j][i+1],j});
			}
		}
		SORT(arr);
		REP(j, remain) {
			int idx = arr[j].second;
			ans[idx] = {mp[idx][i], mp[idx][i+1]};
			taken.insert(idx);
		}
	}
	for (auto [s,e]: ans) {
		cout<<s+1<<" "<<e+1<<"\n";
	}
}