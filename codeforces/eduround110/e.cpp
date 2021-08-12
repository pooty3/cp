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
unordered_map<int, vi> dpmp;
unordered_map<int, pair<ll,ll>> arr;

int findNonZero(int u) {
	if (arr[u].first == 0) {
		return u;
	}
	int prev = u;
	for (auto v : dpmp[u]) {
		if (arr[v].first == 0) {
			break;
		}
		prev = v;
	}
	if (prev == u) return u;
	return findNonZero(prev);
}
int main()
{
	int q;
	ll a,c;
	cin>>q>>a>>c;
	arr[0] = {a,c};
	dpmp.insert({0, vi()});
	REP(i, q) {
		int ind;
		cin>>ind;
		if (ind == 1) {
			int p;
			cin>>p>>a>>c;
			arr[i+1] = {a,c};
			int zz = i+1;
			dpmp.insert({zz, vi()});
			dpmp[zz].push_back(p);	
			int cur =1;
			while (true) {
				int nind = dpmp[zz][cur-1];
				if (dpmp[nind].size()<cur) {
					break;
				}
				dpmp[zz].push_back(dpmp[nind][cur-1]);
				cur++;
			}
		} if (ind == 2) {
			int u;
			ll tot = 0;
			ll totamt =0;
			ll w;
			cin>>u>>w;
			while (true) {
				int v = findNonZero(u);
				if (arr[v].first == 0) {
					break;
				}
				ll amt = min(arr[v].first, w);
				tot += amt*arr[v].second;
				totamt += amt;
				arr[v] = {arr[v].first- amt, arr[v].second};
				w -= amt;
				if (w ==0) break;
			}
			cout<<totamt<<" "<<tot<<endl;
		}
	}

}