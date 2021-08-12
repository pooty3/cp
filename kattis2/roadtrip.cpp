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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	ll n,g;
	cin>>n>>g;
	vector<pair<ll,ll>> arr(n+1);
	arr[0] = {0,0};
	REP(i, n) {
		ll x, c;
		cin>>x>>c;
		arr[i+1] = {x,c};
	}
	SORT(arr);
	ll tot=0;
	set<pair<ll,ll>> mp;
	mp.insert({0,0});
	REPL(i,1, n+1) {
		ll curst = arr[i-1].first;
		while (true) {
			if (mp.empty()) {
				cout<<"cancel road trip";
				return 0;
			}
			auto &[c, dist] = *mp.begin();

			if (dist + g >= arr[i].first) {
				tot += (arr[i].first - curst) * c;
				mp.insert({arr[i].second, arr[i].first});
				break;
			}
			tot += max(0LL, dist + g - curst) * c;
			curst = max(curst, dist + g);
			mp.erase(mp.begin());

		}

	}
	cout<<tot;
}