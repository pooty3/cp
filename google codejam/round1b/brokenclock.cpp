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
int hrs = 1;
int mns = 12;
int secs = 720;
ll oneround =  12LL * 60LL*60LL*1000000000LL;
int csss=0;
bool trysolve(ll A, ll B, ll C) {
	set<ll> possiblens;
	int st = B<A ? 1:0;
	REPL(i,st, 12 +st) {
		ll val = i*oneround + (B-A);
		if (val%11==0) {
			ll ns = val/11LL;
			possiblens.insert(ns);
		}
	} 
	if (possiblens.empty()) return false;
	for (auto ns: possiblens) {
		ll x = A-ns; 
		B = (B-x+oneround)%oneround;
		C = (C-x+oneround)%oneround;
		if ((ns*12LL)%oneround != B || (ns*720LL)%oneround != C) {
			continue;
		}
		ll vvvv = 1e9;
		ll nano = ns%vvvv;
		ns/=vvvv;
		ll sec = ns%60;
		ns /=60;
		ll mn = ns%60;
		ns /=60;
		printf("Case #%d: %lld %lld %lld %lld\n", csss, ns, mn, sec, nano);
		return true;
	}
	return false;
}

void solve() {
	csss++;
	ll a,b,c;cin>>a>>b>>c;
	if (trysolve(a,b,c)) return;
	if (trysolve(a,c,b)) return;
	if (trysolve(b,a,c)) return;
	if (trysolve(b,c,a)) return;
	if (trysolve(c,b,a)) return;
	if (trysolve(c,a,b)) return;
}

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	int tc;
	cin>>tc;
	REP(i, tc) {
		solve();
	}

}