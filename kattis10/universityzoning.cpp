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
	int r,c,f,s,g;
	cin>>r>>c>>f>>s>>g;

	vector<set<ii>> fac(f, set<ii>());
	REP(i, f) {
		int k;
		cin>>k;
		REP(j, k) {
			int r,c;
			cin>>r>>c;
			fac[i].insert({r,c});
		}
	}
	vector<map<int, ii>> sarr(f, map<int,ii>());
	REP(i, s) {
		int r,c,ff, d;
		cin>>r>>c>>d>>ff;ff--;
		sarr[ff].insert({d, {r,c}});
	}
	multiset<ll> dist;
	vi tval(f);
	REP(i, f) {
		cin>>tval[i];
	}
	REP(i, f) {
		auto it = fac[i].begin();
		auto it2 = sarr[i].begin();
		multiset<ll> vals;
		while (it2!= sarr[i].end()) {
			auto [r1,c1] = *it;
			auto [r2,c2] = it2->second;
			ll dis = abs(r1-r2) + abs(c1-c2);
			vals.insert(dis);
			it++;
			it2++;
		}
		auto curit = vals.begin();
		ll curtot = 0;
		REP(j, tval[i]) {
			curtot += *curit;
			curit++;
		}
		dist.insert(curtot);
	}
	ll ftot =0;
	auto curit2 = dist.begin();
	REP(i, g) {
		ftot += *curit2;
		curit2++;
	}	cout<<ftot;
}