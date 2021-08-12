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


int solvehalf(vi &barr, vi &sarr) {
	int n = barr.size();
	map<int, int>bmp;
	REP(i, n) {
		bmp.insert({barr[i], i});
	}
	int m = sarr.size();
	map<int,int> smp;
	REP(i, m) {
		smp.insert({sarr[i],i});
	}
	vi alrarray(m,0);
	int cur =0;
	REP(i, m) {
		int curind = m-1-i;
		if (bmp.find(sarr[curind])!=bmp.end()) {
			cur++;
		}
		alrarray[curind] = cur;
	}
	int curmx = cur;
	REP(i, m) {
		int boxes;
		auto boxit = bmp.upper_bound(sarr[i]);
		if (boxit == bmp.end()) {
			boxes = n;
		} else {
			boxes = boxit -> second;
		}
		auto mnit = smp.upper_bound(sarr[i]-boxes);
		int mnspecial;
		if (mnit == smp.end()) {
			mnspecial = m;
		} else {
			mnspecial = mnit->second;
		}
		int amt = i - mnspecial + 1;
		if (i != m-1) {
			amt += alrarray[i+1];
		}
		curmx= max(amt, curmx);
	}

	return curmx;
}

void solve() {
	int n,m;
	cin>>n>>m;
	vi negbx, posbx, negsp, possp;
	REP(i, n) {
		int x;
		cin>>x;
		if (x<0) {
			negbx.push_back(-x);
		} else {
			posbx.push_back(x);
		}
	}
	REP(i, m) {
		int x;
		cin>>x;
		if (x<0) {
			negsp.push_back(-x);
		} else {
			possp.push_back(x);
		}
	}
	SORT(negbx);
	SORT(negsp);
	cout<<solvehalf(negbx, negsp) + solvehalf(posbx, possp)<<"\n";
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