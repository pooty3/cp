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
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int n,m,p;
	cin>>n>>m>>p;
	vll arr;
	REP(i, n){
		string s;
		cin>>s;
		ll cur=0;
		REP(j, m) {
			if (s[j]=='1') {
				cur += (1LL<<j);
			}
		}
		arr.push_back(cur);
	}
	ll curb = 0;
	REP(ttt, 20) {
		int idx = uniform_int_distribution<int>(0, n-1)(rng);
		vi sarr;
		REP(i,m) {
			if (arr[idx]&(1LL<<i)) {
				sarr.push_back(i);
			}
		}
		map<int, int> masks;
		for (auto v:arr) {
			int cur = 0;
			REP(i, sarr.size()) {
				if (v&(1LL<<sarr[i])) {
					cur += (1<<i);
				}
			}
			masks[cur]++;
		}
		vi fmasks((1<<p), 0);
		for (auto [vv, c]: masks) {
			for (int ss = vv; ss; ss = (ss-1)&vv) {
				fmasks[ss] += c;
			}
		}

		REP(i, (1<<p)) {
			if (fmasks[i]*2>=n) {
				ll fin = 0;
				REP(j, sarr.size()) {
					if (i&(1<<j)) {
						fin += 1LL<<(sarr[j]);
					}
				}
				if (__builtin_popcountll(fin)> __builtin_popcountll(curb)) {
					curb = fin;
				}
			}
		}
	}
	REP(i, m) {
		if (curb&(1LL<<i)) {
			cout<<1;
		} else {
			cout<<0;
		}
	}
}