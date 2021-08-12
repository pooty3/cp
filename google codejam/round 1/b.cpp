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

ll curbst =0;
ll tot =0;
set<ll> tried;
map<int,ll> mp;
void recurse(ll curV, ll curM) {
	if (tried.find(curM)!= tried.end()) return;
	tried.insert(curM);
	for (auto [p, n]: mp) {
		if (n == 0) continue;
		if (curM*p == tot - curV-p) {
			curbst = max(curM*p, curbst);
		}
		if (curM*p < tot- curV-p) {
			mp[p]--;
			recurse(curV +p, curM*p);
			mp[p]++;
		}
	}
}

void solve(int zz) {
	int m;
	cin>>m;
	mp.clear();
	tried.clear();
	tot =0;
	curbst =0;
	REP(i, m) {
		int p;
		ll n;
		cin>>p>>n;
		mp.insert({p,n});
		tot += p*n;
	}
	recurse(0,1);
	cout<<"Case #"<<zz<<": "<<curbst<<"\n";

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int tc;
	cin>>tc;
	REP(i, tc) {
		solve(i+1);
	}

}