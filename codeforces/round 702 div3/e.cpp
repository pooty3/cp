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
	int n;
	cin>>n;
	map<ll,set<int>> mp;
	vll arr(n);
	REP(i, n) {
		cin>>arr[i];
		if (mp.find(arr[i])==mp.end()) {
			mp.insert({arr[i], set<int>()});
		}
		mp[arr[i]].insert(i+1);
	}
	SORT(arr);
	int least =0;
	ll curmax =0;
	REP(i, n-1) {
		curmax+= arr[i];
		if (curmax < arr[i+1]) {
			least = i+1;
		}
	}
	set<int> winarr;
	ll prev =-1;
	REPL(i, least, n) {
		if (prev == arr[i]) continue;
		prev=arr[i];
		FOREACH(it, mp[arr[i]]) {
			winarr.insert(*it);
		}
	}
	cout<<winarr.size()<<"\n";
	FOREACH(it, winarr) {
		cout<<(*it)<<" ";
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