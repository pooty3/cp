#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
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

int main()
{
	int n,k;
	cin>>n>>k;
	vector<pair<ll,ll>> acts(n);
	map<ll, int> mp;
	mp.insert({0, k});
	REP(i, n) {
		ll s, f;
		cin>>s>>f;
		acts[i] = {f,s};
	}
	sort(acts.begin(), acts.end());
	int tot =0;
	FOREACH(it, acts) {
		ll s = it->second;
		ll f = it->first;
		auto it2 = mp.lower_bound(s);
		if (it2 == mp.begin()) {
			continue;
		} else {
			tot++;
			it2 = prev(it2);
			(it2 -> second)--;
			if (it2->second ==0) {
				mp.erase(it2);
			}

			if (mp.find(f)!=mp.end()) {
				mp[f]++;
			} else {
				mp.insert({f, 1});
			}
		}
	}
	cout<<tot;


}