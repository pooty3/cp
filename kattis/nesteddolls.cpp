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

struct doll {
	ll w;
	ll h;
	bool operator<(doll &other) const {
		return (this->w < other.w)||(this->w== other.w && this->h > other.h);
	}
};
void solve() {
	int m;
	cin>>m;
	vector<doll> arr(m);
	REP(i, m) {
		ll w,h;
		cin>>w>>h;
		arr[i] = {w,h};
	}
	SORT(arr);
	map<int, int> mp;
	FOREACH(it, arr) {
		auto it2 = mp.lower_bound(it->h);
		if (it2!=mp.begin()) {
			it2 = prev(it2);
			it2->second--;
			if (it2->second ==0) {
				mp.erase(it2);
			}
		} 
		if (mp.find(it->h)!=mp.end()) {
			mp[it->h]++;
		} else {
			mp.insert({it->h, 1});
		}
	}
	int tot =0;
	FOREACH(it, mp) {
		tot += it->second;
	}
	cout<<tot<<"\n";



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