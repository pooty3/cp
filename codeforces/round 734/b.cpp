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
	int n,k;
	cin>>n>>k;
	map<int, vi> mp;
	REP(i, n) {
		int x;
		cin>>x;
		if (mp.find(x)==mp.end()) {
			mp.insert({x, vi()});
		}
		mp[x].push_back(i);
	}
	int tot =0;
	vii arr;
	for (auto [i,sss]: mp) {
		int toins = min(k, (int)sss.size());
		tot += toins;
		REP(j, toins) {
			arr.push_back({i, j});
		}
	}
	vi farr(n, 0);
	REP(i, (tot/k)*k) {
		auto [val, ind] = arr[i];
		farr[mp[val][ind]] = i%k+1;
	}
	REP(i, n) {
		cout<<farr[i]<<" ";
	}cout<<"\n"


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