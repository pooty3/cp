#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define SORT(arr) sort(arr.begin(), arr.end())
#define LSOne(S) ((S)&-(S))
#define M_PI 3.1415926535897932384
#define INF 1999999999999
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
	ll n,m;
	cin>>n>>m;
	vll arr(n);
	ll tot=0;
	ll cur =0;
	map<ll, ll> mp;
	REP(i,n) {
		cin>>arr[i];
		tot += arr[i];
		if (tot > 0) {
			if (mp.size()==0 || (mp.rbegin())->first < tot) {
				mp.insert({tot, i});
			}
		}
	}
	ll mx = mp.size()>0? (mp.rbegin())->first:0;
	REP(i ,m) {
		ll x;
		cin>>x;
		if (tot <= 0 && mx < x) {
			cout<<-1<<" ";
		} else {
			ll xtra =0;
			if (x > mx) {
				ll def = x - mx;
			 	xtra = def/tot;
				if (def%tot !=0) {
					xtra++;
				}
				x -= xtra * tot;
			}
			auto it = mp.lower_bound(x);
			cout<<(xtra* n + it->second)<<" ";
		}
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